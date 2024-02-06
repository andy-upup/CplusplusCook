#include "as_const_module.h"

void TestAsConst() {
    std::string str = "Hello World!";
    const std::string& const_str = std::as_const(str);
    std::cout << const_str << std::endl;
}