#ifndef AUTO_MODULE_H__
#define AUTO_MODULE_H__
#include <algorithm>
#include <iostream>

namespace cpp14 {

auto ReturnAuto(int i);
// auto ReturnAutoSwitch(bool flag);

template <typename T>
auto ReturnAutoInTemplate(T i) {
  return i;
}

}  // namespace cpp14
#endif