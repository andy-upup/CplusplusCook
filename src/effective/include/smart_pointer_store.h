#ifndef SMART_POINTER_STORE_H__
#define SMART_POINTER_STORE_H__
#include <iostream>
#include <memory>

namespace effective {

struct WidgetSp {
  int val_;
};

inline int Priority() { return 0; }

void ProcessWidget(std::shared_ptr<WidgetSp> widget, int priority);

}  // namespace effective
#endif