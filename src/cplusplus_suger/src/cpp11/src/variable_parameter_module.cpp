#include "variable_parameter_module.h"

void VairFun(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int arg = va_arg(args, int);
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    va_end(args);
}