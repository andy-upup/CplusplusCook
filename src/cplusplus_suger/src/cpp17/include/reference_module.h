#ifndef REFERENCE_MODULE_H__
#define REFERENCE_MODULE_H__
#include <iostream>

// new reference collapsing, more convenient
template<typename... Ts>
auto ComputeSum(Ts... ts) {
    return (ts + ...);
}
#endif