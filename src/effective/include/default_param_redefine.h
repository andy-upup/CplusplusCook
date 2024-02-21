#ifndef DEFAULT_PARAM_REDEFINE_H__
#define DEFAULT_PARAM_REDEFINE_H__
#include <iostream>

namespace effective {

class Shape {
 public:
    enum ShapeColor { RED, GREEN, BLUE };
    virtual void Draw(ShapeColor color = RED) const = 0;
};

class Triangle : public Shape {
 public:
    virtual void Draw(ShapeColor color = GREEN) const {
        std::cout << "Triangle shape color is: " << color << std::endl;
    }
};

class Circle : public Shape {
 public:
    virtual void Draw(ShapeColor color) const {
        std::cout << "Circle shape color is: " << color << std::endl;
    }
};

} // namespace effective
#endif