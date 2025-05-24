#include "class_module.h"

namespace cpp11 {

Foo::Foo(int val) : val_(val) {
  std::cout << "Construct function: " << val << std::endl;
}

Foo::Foo(const Foo& input) {
  val_ = input.val_;
  std::cout << "Copy-construct function." << std::endl;
}

void Foo::Print() { std::cout << "Function Print." << std::endl; }

}  // namespace cpp11