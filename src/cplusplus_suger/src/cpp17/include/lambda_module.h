#ifndef LAMBDA_MODULE_H__
#define LAMBDA_MODULE_H__
#include <iostream>

// capture *this
struct ThisSample {
    int val = 10;
    void Func() {
        auto capture_func = [*this] {
            std::cout << "val: " << val << std::endl;
        };
        capture_func();
    }
};

int GetSquare(int n);
#endif