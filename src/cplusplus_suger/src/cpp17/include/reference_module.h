#ifndef REFERENCE_MODULE_H__
#define REFERENCE_MODULE_H__
#include <iostream>

namespace cpp17 {

// new reference collapsing, more convenient
template<typename... Ts>
auto ComputeSum(Ts... ts) {
    return (ts + ...);
}

} // namespace cpp17
#endif