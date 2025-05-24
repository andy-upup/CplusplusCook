#include <gtest/gtest.h>
#include <time.h>

#include <cstdlib>
#include <iostream>

#include "sort.h"

static void GenVec(std::vector<int>& vec, const int min, const int max) {
  std::srand((unsigned)time(NULL));
  const int size = vec.size();
  for (int i = 0; i < size; ++i) {
    vec[i] = (rand() % (max - min)) + min;
  }
}

static void CoutVec(std::vector<int>& vec) {
  const int size = vec.size();
  for (int i = 0; i < size; ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

TEST(test_algo_sort, bubble_sort_unit_test) {
  std::vector<int> vec(10, 0);
  GenVec(vec, 0, 10);
  CoutVec(vec);
  algo::BubbleSort(vec);
  CoutVec(vec);
}

TEST(test_algo_sort, selection_sort_unit_test) {
  std::vector<int> vec(10, 0);
  GenVec(vec, 0, 10);
  CoutVec(vec);
  algo::SelectionSort(vec);
  CoutVec(vec);
}

TEST(test_algo_sort, insertion_sort_unit_test) {
  std::vector<int> vec(10, 0);
  GenVec(vec, 0, 10);
  CoutVec(vec);
  algo::InsertionSort(vec);
  CoutVec(vec);
}

TEST(test_algo_sort, shell_sort_unit_test) {
  std::vector<int> vec(10, 0);
  GenVec(vec, 0, 10);
  CoutVec(vec);
  algo::ShellSort(vec, 4);
  CoutVec(vec);
}

TEST(test_algo_sort, merge_sort_unit_test) {
  std::vector<int> vec(10, 0);
  GenVec(vec, 0, 10);
  CoutVec(vec);
  algo::MergeSort(vec);
  CoutVec(vec);
}

TEST(test_algo_sort, quick_sort_unit_test) {
  std::vector<int> vec(10, 0);
  GenVec(vec, 0, 10);
  CoutVec(vec);
  algo::QuickSort(vec);
  CoutVec(vec);
}

TEST(test_algo_sort, heap_sort_unit_test) {
  std::vector<int> vec(10, 0);
  GenVec(vec, 0, 10);
  CoutVec(vec);
  algo::HeapSort(vec);
  CoutVec(vec);
}