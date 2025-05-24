#include "heap_module.h"

namespace cpp11 {

void TestMaxHeap(std::vector<int>& vec) {
  if (vec.empty()) {
    std::cout << "Empty input!" << std::endl;
    return;
  }
  for (int i = 0; i < (int)vec.size(); ++i) {
    std::cout << vec[i] << ' ';
  }
  std::cout << std::endl;
  std::make_heap(vec.begin(), vec.end());
  std::cout << "Max value of initial vec is: " << vec.front() << std::endl;
  int new_max = vec.front() + 1;

  std::pop_heap(vec.begin(), vec.end());
  vec.pop_back();
  std::cout << "After pop, max value of vec is: " << vec.front() << std::endl;

  vec.push_back(new_max);
  std::push_heap(vec.begin(), vec.end());
  std::cout << "After push, max value of initial vec is: " << vec.front()
            << std::endl;
  return;
}

void TestMinHeap(std::vector<int>& vec) {
  if (vec.empty()) {
    std::cout << "Empty input!" << std::endl;
    return;
  }
  for (int i = 0; i < (int)vec.size(); ++i) {
    std::cout << vec[i] << ' ';
  }
  std::cout << std::endl;

  // cmp for heap is opposite to cmp for sort
  auto cmp = [](const int x, const int y) { return x > y; };

  std::make_heap(vec.begin(), vec.end(), cmp);
  std::cout << "Min value of initial vec is: " << vec.front() << std::endl;
  int new_min = vec.front() - 1;

  std::pop_heap(vec.begin(), vec.end(), cmp);
  vec.pop_back();
  std::cout << "After pop, min value of vec is: " << vec.front() << std::endl;

  vec.push_back(new_min);
  std::push_heap(vec.begin(), vec.end(), cmp);
  std::cout << "After push, min value of initial vec is: " << vec.front()
            << std::endl;

  std::sort(vec.begin(), vec.end(), cmp);
  for (int i = 0; i < (int)vec.size(); ++i) {
    std::cout << vec[i] << ' ';
  }
  std::cout << std::endl;
  return;
}

void TestMaxHeap(std::vector<std::pair<int, int>>& vec) {
  if (vec.empty()) {
    std::cout << "Empty input!" << std::endl;
    return;
  }
  for (int i = 0; i < (int)vec.size(); ++i) {
    std::cout << vec[i].first << ": " << vec[i].second << ", ";
  }
  std::cout << std::endl;

  auto cmp = [](const std::pair<int, int>& x, const std::pair<int, int>& y) {
    return x.first < y.first;
  };
  std::make_heap(vec.begin(), vec.end(), cmp);
  std::cout << "Max value of initial vec is: " << vec.front().first << ": "
            << vec.front().second << std::endl;

  std::pop_heap(vec.begin(), vec.end(), cmp);
  std::cout << "After pop, max value of initial vec is: " << vec.front().first
            << ": " << vec.front().second << std::endl;
}

}  // namespace cpp11