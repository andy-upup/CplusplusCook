#include "swap_without_mem.h"

namespace others {

void SwapWithoutMemArithmetic(int& x, int& y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

void SwapWithoutMemXor(int& x, int& y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

} // namespace others