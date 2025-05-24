#ifndef CONSTEXPR_MODULE_H__
#define CONSTEXPR_MODULE_H__
#include <array>
#include <iostream>

namespace cpp11 {

class Type {
 public:
  constexpr Type(const char *name, int age) : name_(name), age_(age){};
  constexpr const char *GetName() { return name_; };
  constexpr int GetAge() { return age_; };

 private:
  const char *name_;
  int age_;
};

// void DisplayWithParam(const int x);
void DisplayNoParam();
void ReassignToReadOnlyVar();
void InitialArray();

}  // namespace cpp11
#endif