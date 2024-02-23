#include <gtest/gtest.h>

#include <iostream>

#include "default_param_redefine.h"

TEST(test_effective, default_param_redefine_unit_test) {
    // effective::Shape *shape;
    effective::Shape *triangle = new effective::Triangle;
    effective::Shape *circle = new effective::Circle;

    triangle->Draw();
    triangle->Draw(effective::Shape::RED);
    circle->Draw(effective::Shape::RED);
}