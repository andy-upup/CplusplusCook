#ifndef TEMPLATE_MODULE_H__
#define TEMPLATE_MODULE_H__
#include <iostream>
#include <map>

namespace cpp11 {

template <typename T>
using str_map = std::map<std::string, T>;

template <typename T>
using func = void (*)(T, T);

template<typename T>
void Display(T t) {
    std::cout << t << std::endl;
}

template <typename F, typename... Args>
void Executor(const F func, Args&&... args) {
    int result = func(args...);
    std::cout << "Executor result is: " << result << std::endl;
}

//////////////////////////////////////////////////////////////
/////////////////class template specialization////////////////
//////////////////////////////////////////////////////////////
template<typename T1, typename T2>
class TempPartial {
 public:
    void Print(const T1 v1, const T2 v2) {
        std::cout << "Original class: " << v1 << ' ' << v2 << std::endl;
    }
};

template<typename T1>
class TempPartial<T1, int> {
 public:
    void Print(const T1 v1, const int v2) {
        std::cout << "Partial specialization int class: " << v1 << ' ' << v2 << std::endl;
    }
};

template<>
class TempPartial<int, float> {
 public:
    void Print(const int v1, const float v2) {
        std::cout << "Specialization int and float class: " << v1 << ' ' << v2 << std::endl;
    }
};

//////////////////////////////////////////////////////////////
///////////////function template specialization///////////////
//////////////////////////////////////////////////////////////
template<const int VAL>
void FuncTempPrint();

// Add inline or move the following functions to .cpp,
// otherwise it will case multiple definition.
template<> inline
void FuncTempPrint<10>() {
    std::cout << "Function specialization: " << 10 << std::endl;
}

template<> inline
void FuncTempPrint<100>() {
    std::cout << "Function specialization: " << 100 << std::endl;
}

int ComputeSum(const int x, const int y);

} // namespace cpp11
#endif