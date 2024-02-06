#ifndef AUTO_MODULE_H__
#define AUTO_MODULE_H__
#include <algorithm>
#include <iostream>

auto ReturnAuto(int i);
// auto ReturnAutoSwitch(bool flag);

template<typename T>
auto ReturnAutoInTemplate(T i) {
    return i;
}
#endif