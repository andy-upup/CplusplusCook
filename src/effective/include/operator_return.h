#ifndef OPERATOR_RETURN_H__
#define OPERATOR_RETURN_H__
#include <iostream>

namespace effective {

// Have assignment operators return a reference to *this
class Widget {
 public:
  Widget& operator=(const Widget& rhs) {
    this->num_ = rhs.num_;
    return *this;
  }

  Widget& operator+=(const Widget& rhs) {
    this->num_ += rhs.num_;
    return *this;
  }

 private:
  int num_;
};

}  // namespace effective
#endif