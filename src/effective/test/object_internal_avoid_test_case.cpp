#include <gtest/gtest.h>

#include <iostream>

#include "object_internal_avoid.h"

TEST(test_effective, object_internal_avoid_unit_test) {
    effective::Point upper_left_point(10, 10);
    effective::Point lower_right_point(100, 100);
    effective::RectData rect = {upper_left_point, lower_right_point};

    std::shared_ptr<effective::RectData> prect = std::make_shared<effective::RectData>(rect);
    const effective::Rectangle rectangle(prect);

    std::cout << "upper_left_point is: " << rectangle.GetUpperLeft().GetX() << " " << rectangle.GetUpperLeft().GetY() << std::endl;
    rectangle.GetUpperLeft().SetX(50);
    std::cout << "upper_left_point is: " << rectangle.GetUpperLeft().GetX() << " " << rectangle.GetUpperLeft().GetY() << std::endl;
}
