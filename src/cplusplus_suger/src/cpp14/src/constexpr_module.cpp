#include "constexpr_module.h"

constexpr int Factorial(int n) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += i;
    }
    return ret;
}