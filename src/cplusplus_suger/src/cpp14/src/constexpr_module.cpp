#include "constexpr_module.h"

namespace cpp14 {

constexpr int Factorial(int n) {
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += i;
  }
  return ret;
}

}  // namespace cpp14