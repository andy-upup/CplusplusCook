#include "if_switch_module.h"

namespace cpp17 {

static constexpr int GetValue() {
    return 100;
}

void IfSwitch(int n) {
    if (int i = GetValue(); i < n) {
        std::cout << i << std::endl;
    } else {
        std::cout << "Wrong input!" << std::endl;
    }
}

} // namespace cpp17