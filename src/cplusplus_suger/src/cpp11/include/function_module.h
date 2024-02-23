#ifndef FUNCTION_MODULE_H__
#define FUNCTION_MODULE_H__
#include <functional>
#include <iostream>

namespace cpp11 {

int FunctionSum(const int x, const int y);
int FunctionSumLambda(const int x, const int y);
int FunctionSumClass(const int x, const int y);
int FunctionSumClassObject(const int x, const int y);
int FunctionSumClassBind(const int x, const int y);

template<typename T>
T ComputeSumOrdTem(T x, T y) {
    return x + y;
}

class FunctorOpInt {
 public:
    int operator() (const int x, const int y) {
        return x + y;
    }
};

template<typename T>
class FunctorOpTem {
 public:
    T operator() (T x, T y) {
        return x + y;
    }
};

class Functor {
 public:
    int ComputeSumInt(int x, int y) {
        return x + y;
    }
    static int ComputeSumStInt(const int x, const int y) {
        return x + y;
    }
    template<typename T>
    T ComputeSumTem(T x, T y) {
        return x + y;
    }
    template<typename T>
    static T ComputeSumStTem(T x, T y) {
        return x + y;
    }
};

class FunctorBind {
 public:
    int ComputeSumInt(const int x, const int y) {
        return x + y;
    }
    static int ComputeSumStInt(const int x, const int y) {
        return x + y;
    }
    template<typename T>
    T ComputeSumTem(T x, T y) {
        return x + y;
    }
};

} // namespace cpp11
#endif