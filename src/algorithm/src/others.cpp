#include "others.h"

namespace algo {

int JuiceNum(const int n) {
    int total = n;
    int empty = n;
    int carry = 0;
    while (empty >= 1) {
        empty += carry;
        carry = (empty & 1);
        empty >>= 1;
        total += empty;
    }
    return total;
}

} // namespace algo