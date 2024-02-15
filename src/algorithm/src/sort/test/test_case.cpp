#include <gtest/gtest.h>
#include <time.h>

#include <cstdlib>
#include <iostream>

#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"

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

TEST(test_algo_sort, bubble_sort_test_case) {
    std::vector<int> vec(10, 0);
    GenVec(vec, 0, 10);
    CoutVec(vec);
    BubbleSort(vec);
    CoutVec(vec);
}

TEST(test_algo_sort, selection_sort_test_case) {
    std::vector<int> vec(10, 0);
    GenVec(vec, 0, 10);
    CoutVec(vec);
    SelectionSort(vec);
    CoutVec(vec);
}

TEST(test_algo_sort, insertion_sort_test_case) {
    std::vector<int> vec(10, 0);
    GenVec(vec, 0, 10);
    CoutVec(vec);
    InsertionSort(vec);
    CoutVec(vec);
}

TEST(test_algo_sort, shell_sort_test_case) {
    std::vector<int> vec(10, 0);
    GenVec(vec, 0, 10);
    CoutVec(vec);
    ShellSort(vec, 4);
    CoutVec(vec);
}

TEST(test_algo_sort, merge_sort_test_case) {
    std::vector<int> vec(10, 0);
    GenVec(vec, 0, 10);
    CoutVec(vec);
    MergeSort(vec);
    CoutVec(vec);
}