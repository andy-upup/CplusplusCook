#include "lambda_module.h"

// combining constexpr with lambda is supported in C++17
int GetSquare(int n) {
    constexpr auto compute_square = [] (int i) {
        return i * i;
    };
    return compute_square(n);
}