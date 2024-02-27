#ifndef SINGLETON_H__
#define SINGLETON_H__
#include <iostream>
#include <memory>
#include <mutex>

namespace design_pattern {
// Static objects will be automatically destroyed when the program ends, that is, their destructors will be automatically called when main() ends.

// Lazy initialization initializes only when needed.
// Hungry initialization is initialized at the beginning of the system.

// lazy initialization with lock
class LSingletonWithLock {
 public:
   ~LSingletonWithLock() {};
   static std::shared_ptr<LSingletonWithLock> GetInstance();
   void Print();
 private:
   LSingletonWithLock() {};
   LSingletonWithLock(const LSingletonWithLock&) = delete;
   LSingletonWithLock& operator=(const LSingletonWithLock&) = delete;
};

// lazy initialization with local static
class LSingletonWithStatic {
 public:
   static LSingletonWithStatic& GetInstance();
   void Print();
 private:
   LSingletonWithStatic() {};
   ~LSingletonWithStatic() {};
   LSingletonWithStatic(const LSingletonWithStatic&) = delete;
   LSingletonWithStatic& operator=(const LSingletonWithStatic&) = delete;
};

// hungray initialization
class HSingletonWithStatic {
 public:
   static HSingletonWithStatic* GetInstance();
   static void DeleteInstance();
   void Print();
 private:
   HSingletonWithStatic() {};
   ~HSingletonWithStatic() {};
   HSingletonWithStatic(const HSingletonWithStatic&) = delete;
   HSingletonWithStatic& operator=(const HSingletonWithStatic&) = delete;
 private:
   static HSingletonWithStatic *singleton_;
};

// hungray initialization with call_once
class HSingletonWithCallOnce {
 public:
   ~HSingletonWithCallOnce() {};
   static std::shared_ptr<HSingletonWithCallOnce> GetInstance();
   void Print();
 private:
   HSingletonWithCallOnce() {};
   HSingletonWithCallOnce(const HSingletonWithCallOnce&) = delete;
   HSingletonWithCallOnce& operator=(const HSingletonWithCallOnce&) = delete;
};

} // namespace design_pattern
#endif