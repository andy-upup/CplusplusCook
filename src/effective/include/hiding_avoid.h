#ifndef HIDING_AVOID_H__
#define HIDING_AVOID_H__
#include <iostream>
namespace effective {

class HidingBase {
 public:
    virtual void Mf1() = 0;
    virtual void Mf1(int x) { std::cout << "Base::Mf1(int): " << x << std::endl; }
    virtual void Mf2() { std::cout << "Base::Mf2()" << std::endl; }
    void Mf3() { std::cout << "Base::Mf3()" << std::endl; }
    void Mf3(double x) { std::cout << "Base::Mf3(double): " << x << std::endl; }
};

class HidingDerivedX : public HidingBase {
 public:
    virtual void Mf1() { std::cout << "DerivedX::Mf1()" << std::endl; }
    void Mf3() { std::cout << "DerivedX::Mf3()" << std::endl; }
    void Mf4() { std::cout << "DerivedX::Mf4()" << std::endl; }
};

class HidingDerivedY : public HidingBase {
 public:
    // Make everything named Mf1 and Mf3 in the Base class visible in the Derived scope.
    using HidingBase::Mf1;
    using HidingBase::Mf3;
    virtual void Mf1() { std::cout << "DerivedY::Mf1()" << std::endl; }
    void Mf3() { std::cout << "DerivedY::Mf3()" << std::endl; }
    void Mf4() { std::cout << "DerivedY::Mf4()" << std::endl; }
};

} // namespace effective
#endif