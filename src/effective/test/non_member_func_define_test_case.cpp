#include <gtest/gtest.h>

#include <iostream>

#include "non_member_func_define.h"

TEST(test_effective, non_member_func_define_unit_test) {
    effective::Rational<int> one_half(1, 2);
	effective::Rational<int> result = one_half * 2;
    result.Print();
}