#include "apply_module.h"

namespace cpp17 {

int GetTwoSum(int first, int second) { return first + second; }

auto add_two_sum = [](auto first, auto second) { return first + second; };

// use std::apply to expand a tuple as arguments for a function
void ApplyComputeSum(int first, int second) {
  std::cout << std::apply(GetTwoSum, std::pair(first, second)) << std::endl;
  std::cout << std::apply(add_two_sum, std::tuple(20, 30)) << std::endl;
}

Foo::Foo(int first, float second, int third) {
  std::cout << first << " " << second << " " << third << std::endl;
};

}  // namespace cpp17