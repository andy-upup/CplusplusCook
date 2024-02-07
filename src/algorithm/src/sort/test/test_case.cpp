#include <gtest/gtest.h>
#include <time.h>

#include <cstdlib>
#include <iostream>

#include "bubble_sort.h"

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