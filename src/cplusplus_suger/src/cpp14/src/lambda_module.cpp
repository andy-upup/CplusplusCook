#include "lambda_module.h"

namespace cpp14 {

// parameter type of lambda is auto, this is not allowed in C++11
void InputAutoArg() {
    auto func = [] (auto i) { return i; };
    std::cout << func(99) << std::endl;
    std::cout << func(9.f) << std::endl;
}

} // namespace cpp14