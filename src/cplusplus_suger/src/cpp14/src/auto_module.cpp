#include "auto_module.h"

auto ReturnAuto(int i) {
    return i;
}

// if the function contains multiple returns, 
// the returns must be same type.
auto ReturnAutoSwitch(bool flag) {
    if (flag) {
        return 1;
    } else {
        return 2;
    }
}