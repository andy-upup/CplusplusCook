#include "class_module.h"

namespace cpp11 {

Foo::Foo(int input) {
    std::cout << "Construct function: " << input << std::endl;
}

Foo::Foo(const Foo& input) {
    std::cout << "Copy-construct function." << std::endl;
}

void Foo::Print() {
    std::cout << "Function Print." << std::endl;
}

} // namespace cpp11