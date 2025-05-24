#ifndef NAMESPACE_MODULE_H__
#define NAMESPACE_MODULE_H__
#include <iostream>

namespace cpp17 {

namespace space_x {
namespace space_y {
namespace space_z {
///
}
}  // namespace space_y
}  // namespace space_x

// same as above
namespace space_x::space_y::space_z {
///
}

}  // namespace cpp17
#endif