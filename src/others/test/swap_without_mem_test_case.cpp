#include <gtest/gtest.h>

#include <iostream>

#include "swap_without_mem.h"

TEST(test_others, swap_without_mem_test_case) {
    int x = 10;
    int y = 100;
    std::cout << "x: " << x << ", y: " << y << std::endl;
    others::SwapWithoutMemArithmetic(x, y);
    std::cout << "x: " << x << ", y: " << y << std::endl;

    int m = 9;
    int n = 99;
    std::cout << "m: " << m << ", n: " << n << std::endl;
    others::SwapWithoutMemXor(m, n);
    std::cout << "m: " << m << ", n: " << n << std::endl;
}