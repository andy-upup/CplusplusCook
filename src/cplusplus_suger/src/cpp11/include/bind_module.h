#ifndef BIND_MODULE_H__
#define BIND_MODULE_H__
#include <functional>
#include <iostream>

class BindDemo {
 public:
    void DisplaySum(const int x, const int y) {
        std::cout << "Sum of " << x << " and " << y << " is: " << x + y << std::endl;
    }
};

double BindDivision(const double x);
void BindDisplay(const int y);
#endif