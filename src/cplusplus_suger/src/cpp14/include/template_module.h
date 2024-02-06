#ifndef TEMPLATE_MODULE_H__
#define TEMPLATE_MODULE_H__
#include <iostream>

// C++14 supports variable templates
template<typename T>
constexpr T pi = T(3.1415926535897932385L);

template<typename T, typename U>
struct TemA {
    T t;
    U u;
};

// C++14 supports alias templates
template<typename T>
using TemB = TemA<T, int>;
#endif