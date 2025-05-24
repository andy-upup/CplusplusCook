#include <gtest/gtest.h>

#include <iostream>

#include "smart_pointer_store.h"

TEST(test_effective, smart_pointer_store_unit_test) {
  // Execute new Widget17; call priority; call std::shared_ptr constructor,
  // their execution order is uncertain. Once an exception is thrown, it may
  // lead to resource leaks that are difficult to find.
  effective::ProcessWidget(
      std::shared_ptr<effective::WidgetSp>(new effective::WidgetSp),
      effective::Priority());

  // Store the newed objects as a smart pointers in a standalone statements.
  std::shared_ptr<effective::WidgetSp> widget(new effective::WidgetSp);
  effective::ProcessWidget(widget, effective::Priority());
}