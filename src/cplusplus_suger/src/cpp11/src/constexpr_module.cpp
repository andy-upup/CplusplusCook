#include "constexpr_module.h"

namespace cpp11 {

// const represents read-only, but it is essentially a variable
// void DisplayWithParam(const int x) {
//     std::array<int, x> arr{1, 2, 3, 4, 5};
//     std::cout << arr[1] << std::endl;
// }

// x is immutable and constant, it is deferent from variable
void DisplayNoParam() {
  const int x = 5;
  std::array<int, x> arr{1, 2, 3, 4, 5};
  std::cout << arr[1] << std::endl;
}

// read-only does not mean it can't be modified
void ReassignToReadOnlyVar() {
  int val = 10;
  const int &ref_val = val;
  std::cout << ref_val << std::endl;
  val = 20;
  std::cout << ref_val << std::endl;
}

static constexpr int SqrtWithExpr(int val) { return val * val; }

// static const int SqrtOnlyConst(int val) {
//     return val * val;
// }

void InitialArray() {
  // std::array<int, SqrtOnlyConst(10)> con_array;
  std::array<int, SqrtWithExpr(10)> expr_array;
  std::cout << "Size of expr_array is: " << expr_array.size() << std::endl;
}

}  // namespace cpp11