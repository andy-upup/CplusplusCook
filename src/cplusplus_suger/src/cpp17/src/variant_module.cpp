#include "variant_module.h"

void TestVariant() {
    std::variant<int, std::string> var("hello");
    // get index of current using type
    std::cout << var.index() << std::endl;

    var = 1000;
    std::cout << var.index() << std::endl;

    // get value according to index
    std::cout << std::get<0>(var) << std::endl;
}