#include "bind_module.h"

static double ComputeDivision(const double x, const double y) {
    return x / y;
}

// bind ordinary function
double BindDivision(const double x) {
    // 1st argument of std::bind is function name.
    // when an ordinary function is used as an argument, it will be implicitly converted into a function pointer,
    // equivalent to (&ComputeDivision, _1, 2)

    // std::placeholders::_1 means placeholder, in <functional>, it indicates that this argument needs to be passed in when calling.
    // 2 means a default argument
    auto BindComputeDivision = std::bind(ComputeDivision, std::placeholders::_1, 2);
    return BindComputeDivision(x);
}   

// bind member function
void BindDisplay(const int y) {
    BindDemo bind_demo;
    // 1st argument of std::bind is a pointer to the member function of the object,
    // 2nd argument is the address of the object.
    auto BindDisplaySum = std::bind(&BindDemo::DisplaySum, &bind_demo, 100, std::placeholders::_1);
    BindDisplaySum(y);
}

// bind reference arguments
// use std::ref to pass arguments