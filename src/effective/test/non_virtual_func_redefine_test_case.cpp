#include <gtest/gtest.h>

#include <iostream>

#include "non_virtual_func_redefine.h"

TEST(test_effective, non_virtual_func_redefine_unit_test) {
  effective::NonVirtualDerived derived;
  effective::NonVirtualBase *pbase = &derived;
  pbase->Print();

  effective::NonVirtualDerived *pderived = &derived;
  pderived->Print();
}