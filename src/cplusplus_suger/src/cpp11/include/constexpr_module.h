#ifndef CONSTEXPR_MODULE_H__
#define CONSTEXPR_MODULE_H__
#include <array>
#include <iostream>

namespace cpp11 {

class Type {
 public:
    constexpr Type(const char *name, int age): _name(name), _age(age) {};
    constexpr const char* GetName() {
        return _name;
    };
    constexpr int GetAge() {
        return _age;
    };
 private:
    const char *_name;
    int _age;
};

// void DisplayWithParam(const int x);
void DisplayNoParam();
void ReassignToReadOnlyVar();
void InitialArray();

} // namespace cpp11
#endif