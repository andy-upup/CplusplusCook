#include "smart_pointer_store.h"

namespace effective {

void ProcessWidget(std::shared_ptr<WidgetSp> widget, int priority) {
    std::cout << __func__ << std::endl;
}

} // namespace effective