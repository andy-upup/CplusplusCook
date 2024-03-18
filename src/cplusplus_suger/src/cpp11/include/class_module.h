#ifndef CLASS_MODULE_H__
#define CLASS_MODULE_H__
#include <iostream>

namespace cpp11 {

class Foo
{
public:
    Foo(int);
    void Print();
private:
    Foo(const Foo &);
    int val_;
};

} // namespace cpp11
#endif