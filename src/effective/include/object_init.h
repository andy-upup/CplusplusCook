#ifndef OBJECT_INIT_H__
#define OBJECT_INIT_H__
#include <iostream>
#include <string>

namespace effective {

// The compiler will automatically call the default constructor for member variables of user-defined types.
// If the member variables are const or reference, they must require an initial value and cannot be assigned.
class ABEntry {
 public:
    ABEntry();
    ABEntry(const std::string &name, const std::string &address);
    ABEntry(const std::string &name, const std::string &address, const int phone);
 private:
    std::string name_;
    std::string address_;
    int phone_;
};

} // namespace effective
#endif