#include "class_module.h"

Foo::Foo(int input) {
    std::cout << "Construct function: " << input << std::endl;
}

Foo::Foo(const Foo& input) {
    std::cout << "Copy-construct function." << std::endl;
}

void Foo::Print() {
    std::cout << "Function Print." << std::endl;
}