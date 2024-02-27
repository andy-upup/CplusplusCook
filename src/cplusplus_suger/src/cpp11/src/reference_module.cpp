#include "reference_module.h"

namespace cpp11 {

Demo GetDemo() {
    // construct, copy-construct
    return Demo();
}

void OtherDef(int& val) {
    std::cout << "input: " << val << " is lval!" << std::endl;
}

void OtherDef(const int& val) {
    std::cout << "input: " << val << " is rval!" << std::endl;
}

} // namespace cpp11