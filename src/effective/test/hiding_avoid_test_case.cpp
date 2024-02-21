#include <gtest/gtest.h>

#include <iostream>

#include "hiding_avoid.h"

TEST(test_effective, hiding_avoid_test_case) {
    effective::HidingDerivedX derived_x;
    const int x = 0;
    derived_x.Mf1();     // DerivedX::Mf1()
    // derived_x.Mf1(x); // Wrong, DerivedX::Mf1() hides Base::Mf1(int), regardless of parameter type
    derived_x.Mf2();     // Base::Mf2()
    derived_x.Mf3();     // DerivedX::Mf3()
    // derived_x.Mf3(x); // Wrong, DerivedX::Mf3() hides Base::Mf3(double), regardless of parameter type

    effective::HidingDerivedY derived_y;
    derived_y.Mf1();     // DerivedY::Mf1()
    derived_y.Mf1(x);    // Base::Mf1(int)
    derived_y.Mf2();     // Base::Mf2()
    derived_y.Mf3();     // DerivedY::Mf3()
    derived_y.Mf3(x);    // Base::Mf3(double)
}
