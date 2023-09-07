#include <gtest/gtest.h>
#include <functional>
#include <iostream>

static void Minus(const int i, const int j) {
    std::cout << "Result of Minus is: " << i - j << std::endl;
}

TEST(cpp_suger, function) {
    std::function<void(int, int)> fun = Minus;
    fun(1, 2);
}