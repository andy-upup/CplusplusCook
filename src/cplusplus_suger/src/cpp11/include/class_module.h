#ifndef CLASS_MODULE_H__
#define CLASS_MODULE_H__
#include <iostream>

namespace cpp11 {

class Foo {
 public:
  Foo(int);
  void Print();

 private:
  Foo(const Foo &);
  int val_;
};

class BaseVirtualTest {
 public:
  virtual void PrintClassName() {
    std::cout << "BaseVirtualTest." << std::endl;
  }
  virtual void Print() { std::cout << "Hello World!" << std::endl; }
};

class DerivedVirtualTest : public BaseVirtualTest {
 public:
  virtual void PrintClassName() override {
    std::cout << "DerivedVirtualTest." << std::endl;
  }
};

}  // namespace cpp11
#endif