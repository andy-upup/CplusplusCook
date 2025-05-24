#include <gtest/gtest.h>

#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

/// @brief Multi-thread with local variable.
void foo(int& x) { x += 1; }

/// @brief Multi-thread with mutex and unique_lock.
int a = 0;
std::mutex g_mtx;
std::timed_mutex g_tmtx;

void func() {
  for (int i = 0; i < 1000000; ++i) {
    std::unique_lock<std::timed_mutex> lock(g_tmtx, std::defer_lock);
    lock.try_lock_for(std::chrono::seconds(1));
    a += 1;
  }
}

/// @brief Multi-thread with single instance and call_once.
static std::once_flag only_once;
class Log {
 public:
  Log(const Log& log) = delete;
  Log& operator=(const Log& log) = delete;

  static Log& GetInstance() {
    std::call_once(only_once, Init);
    return *log;
  }

  static void Init() {
    if (!log) {
      log = new Log;
    }
  }
  void PrintLog(const std::string& msg) {
    std::cout << "__TIME__" << msg << std::endl;
  }

 private:
  Log(){};
  static Log* log;
};

Log* Log::log = nullptr;

void PrintLogFunc() {
  Log::GetInstance().PrintLog("Error!");
  return;
}

/// @brief Multi-thread with condition_variable.
std::queue<int> g_queue;
std::condition_variable g_cv;
void Producer() {
  for (int i = 0; i < 10; ++i) {
    {
      std::unique_lock<std::mutex> lock(g_mtx);
      g_queue.push(i);
      g_cv.notify_one();
      std::this_thread::sleep_for(std::chrono::seconds(2));
      std::cout << "Produce: " << i << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(100));
  }
}

void Consumer() {
  while (true) {
    std::unique_lock<std::mutex> lock(g_mtx);
    g_cv.wait(lock, []() { return !g_queue.empty(); });
    int value = g_queue.front();
    g_queue.pop();
    std::cout << "Consume: " << value << std::endl;
  }
}

/// @brief Multi-thread with thread pool.
class ThreadPool {
 public:
  ThreadPool(int thread_num) : m_stop(false) {
    for (int i = 0; i < thread_num; ++i) {
      // Submit lambda as object.
      m_threads.emplace_back([this] {
        while (true) {
          std::unique_lock<std::mutex> lock(m_mtx);
          // Execute all task when the stop flag is true.
          m_condition.wait(lock, [this] { return !m_tasks.empty() || m_stop; });
          if (m_tasks.empty() && m_stop) {
            return;
          }
          std::function<void()> task(std::move(m_tasks.front()));
          m_tasks.pop();
          lock.unlock();
          task();
        }
      });
    }
  }

  ~ThreadPool() {
    {
      std::unique_lock<std::mutex> lock(m_mtx);
      m_stop = true;
    }
    m_condition.notify_all();
    for (auto& t : m_threads) {
      t.join();
    }
  }

  template <class F, class... Args>
  void Enqueue(F&& f, Args&&... args) {
    // Bind function with arguments, so type of function is "void()"
    std::function<void()> task =
        std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    {
      std::unique_lock<std::mutex> lock(m_mtx);
      m_tasks.emplace(std::move(task));
    }
    m_condition.notify_one();
  }

 private:
  std::vector<std::thread> m_threads;
  std::queue<std::function<void()>> m_tasks;
  std::mutex m_mtx;
  std::condition_variable m_condition;
  bool m_stop;
};

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////Test case//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
TEST(thread, local_variable) {
  int n = 1;
  std::thread t(foo, std::ref(n));
  t.join();
}

TEST(thread, mutex) {
  std::thread t1(func);
  std::thread t2(func);
  t1.join();
  t2.join();
  std::cout << "a: " << a << std::endl;
  std::cout << "Finish 2 threads!\n";
}

TEST(thread, print_log) {
  std::thread t1(PrintLogFunc);
  std::thread t2(PrintLogFunc);
  t1.join();
  t2.join();
}

TEST(thread, condition_variable) {
  std::thread t1(Producer);
  std::thread t2(Consumer);
  t1.join();
  t2.join();
}

TEST(thread, thread_pool) {
  ThreadPool pool(4);
  for (int i = 0; i < 10; ++i) {
    pool.Enqueue([i] {
      std::cout << "Task: " << i << " is running." << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << "Task: " << i << " is done." << std::endl;
    });
  }
}