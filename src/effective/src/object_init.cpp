#include "object_init.h"

namespace effective {

ABEntry::ABEntry() : name_(), address_(), phone_(0) {}

ABEntry::ABEntry(const std::string& name, const std::string& address) {
  // Assignments, not initializations.
  // First call the default constructor to set initial values ​​for these
  // variables, and then assign new values ​​to them.
  name_ = name;
  address_ = address;
  phone_ = 2;
}

ABEntry::ABEntry(const std::string& name, const std::string& address, int phone)
    : name_(name), address_(address), phone_(phone) {}

}  // namespace effective