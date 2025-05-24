#ifndef VECTOR_MODULE_H__
#define VECTOR_MODULE_H__
#include <iostream>
#include <vector>

namespace cpp11 {

class Person {
 public:
  Person(int age) : age_(age) {
    std::cout << "Construct a person. " << age_ << std::endl;
  }

  Person(std::string name, int age) : name_(name), age_(age) {
    std::cout << "Construct a person with name. " << age_ << std::endl;
  }

  Person(const Person& p) : age_(p.age_) {
    std::cout << "Copy-Construct: " << age_ << std::endl;
  }

  Person(const Person&& p) noexcept : age_(p.age_) {
    std::cout << "Move-Construct: " << age_ << std::endl;
  }

 private:
  std::string name_;
  int age_;
};

class Back {
 public:
  Back(int t) : i_(t) { std::cout << "Construct" << std::endl; }
  Back(const Back& a) : i_(a.i_) { std::cout << "Copy-Construct" << std::endl; }
  Back(Back&& a) : i_(a.i_) { std::cout << "Move-Construct" << std::endl; }

 private:
  int i_;
};

void VectorSizeTest();

}  // namespace cpp11
#endif