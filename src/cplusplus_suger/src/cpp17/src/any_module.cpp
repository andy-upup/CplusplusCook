#include "any_module.h"

namespace cpp17 {

// any can store a single value of any type
void TestAny() {
    std::any x = 1;
    std::cout << x.type().name() << " " << std::any_cast<int>(x) << std::endl;

    x = 2.2f;
    std::cout << x.type().name() << " " << std::any_cast<float>(x) << std::endl;
    if (x.has_value()) {
        std::cout << x.type().name() << std::endl;
    }

    x.reset();
    if (x.has_value()) {
        std::cout << x.type().name() << std::any_cast<float>(x) << std::endl;
    }

    x = std::string("Hello World!");
    std::cout << x.type().name() << " " << std::any_cast<std::string>(x) << std::endl;
}

} // namespace cpp17