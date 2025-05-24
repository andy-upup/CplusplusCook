#include "template_module.h"

namespace cpp11 {

int ComputeSum(const int x, const int y) { return x + y; }

// template<>
// void FuncTempPrint<10>() {
//     std::cout << "Function specialization: " << 10 << std::endl;
// }

// template<>
// void FuncTempPrint<100>() {
//     std::cout << "Function specialization: " << 100 << std::endl;
// }

}  // namespace cpp11