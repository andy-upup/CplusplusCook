#include <gtest/gtest.h>
#include <iostream>

#include "auto_module.h"
#include "constexpr_module.h"
#include "lambda_module.h"
#include "template_module.h"

TEST(test14_auto, auto_test_case) {
    std::cout << ReturnAutoInTemplate(10) << std::endl;
}

TEST(test14_lambda, lambda_test_case) {
    InputAutoArg();
}

TEST(test14_template, template_test_case) {
    std::cout << pi<int> << std::endl;
    std::cout << pi<double> << std::endl;

    TemB<double> b;
    b.t = 10;
    b.u = 20;
    std::cout << b.t << std::endl;
    std::cout << b.u << std::endl;
}

constexpr int Factorial(int n) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += i;
    }
    return ret;
}

TEST(test14_constexpr, constexpr_test_case) {
    std::cout << Factorial(10) << std::endl;
}