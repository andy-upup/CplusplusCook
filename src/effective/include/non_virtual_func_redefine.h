#ifndef NON_VIRTUAL_FUNC_REDEFINE_H__
#define NON_VIRTUAL_FUNC_REDEFINE_H__
#include <iostream>

namespace effective {

// non-virtual function statically bound
class NonVirtualBase {
 public:
    void Print() {
        std::cout << "NonVirtualBase::Print()" << std::endl;
    }
};

class NonVirtualDerived : public NonVirtualBase {
 public:
    void Print() {
        std::cout << "NonVirtualDerived::Print()" << std::endl;
    }
};

} // namespace effective
#endif