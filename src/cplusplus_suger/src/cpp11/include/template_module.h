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

int ComputeSum(const int x, const int y);

} // namespace cpp11
#endif