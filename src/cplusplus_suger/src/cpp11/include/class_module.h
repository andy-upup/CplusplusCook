#ifndef CLASS_MODULE_H__
#define CLASS_MODULE_H__
#include <iostream>

class Foo
{
public:
    Foo(int);
    void Print();
private:
    Foo(const Foo &);
};
#endif