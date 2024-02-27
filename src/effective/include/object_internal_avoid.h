#ifndef OBJECT_INTERNAL_AVOID_H__
#define OBJECT_INTERNAL_AVOID_H__
#include <iostream>
#include <memory>

namespace effective {

// Avoid returning “handles” to object internals.
// References, pointers and iterators are all so-called handles.
class Point {
 public:
    Point(int x, int y) : x_(x), y_(y) {}

    void SetX(int val) { x_ = val; }
    void SetY(int val) { y_ = val; }

    int GetX() const { return x_; }
    int GetY() const { return y_; }
 private:
    int x_;
    int y_;
};

struct RectData {
    Point upper_left_point;
    Point lower_right_point;
};

class Rectangle {
 public:
    Rectangle(std::shared_ptr<RectData>& rect) : rect_(rect) {}
    // “handles” to object internals
    // Expose internal members to users.
    // Users can modify internal data through references.
    Point& GetUpperLeft() const {
        return rect_->upper_left_point;
    }
    Point& GetLowerRight() const {
        return rect_->lower_right_point;
    }
 private:
    std::shared_ptr<RectData> rect_;
};

} // namespace effective
#endif