#include "lambda_module.h"

int g_num = 0;

bool SortUp(int x, int y) {
    return x < y;
}

void SortWithLambda() {
    int num[4] = {4, 2, 3, 1};
    std::sort(num, num + 4, [](int x, int y) { return x < y; });
    for (int n: num) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

void SortWithFunc() {
    int num[4] = {6, 9, 3, 8};
    std::sort(num, num + 4, SortUp);
    for (int n: num) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

void LambdaRename() {
    auto Display = [](int x, int y)->void { std::cout << x << " " << y << std::endl; };
    Display(100, 10);
}

void PassValVsRef() {
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    auto lambda1 = [=]() mutable {
        g_num = 10;
        num1 = 100;
        num2 = 200;
        num3 = 300;
        std::cout << num1 << " "
                  << num2 << " "
                  << num3 << std::endl;
    };
    std::cout << "Execute lambda1: \n";
    lambda1();
    std::cout << "g_num: " << g_num << std::endl;
    std::cout << num1 << " " << num2 << " " << num3 << std::endl;

    auto lambda2 = [&]() {
        g_num = 100;
        num1 = 10;
        num2 = 20;
        num3 = 30;
        std::cout << num1 << " "
                  << num2 << " "
                  << num3 << std::endl;
    };
    std::cout << "Execute lambda2: \n";
    lambda2();
    std::cout << "g_num: " << g_num << std::endl;
}