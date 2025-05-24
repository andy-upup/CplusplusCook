#ifndef OBJECT_COPY_H__
#define OBJECT_COPY_H__
#include <iostream>

namespace effective {

void CallLog(const std::string& str);

class Customer {
 public:
  Customer(const Customer& rhs) : name_(rhs.name_) {
    CallLog("Customer copy constructor");
  }

  Customer& operator=(const Customer& rhs) {
    CallLog("Customer copy assignment operator");
    this->name_ = rhs.name_;
    return *this;
  }

 private:
  std::string name_;
};

// The copy function should ensure that all member variables and
// all base class components in the object are copied.
class PriorityCustomer : public Customer {
 public:
  // Call copy constructor of base class
  PriorityCustomer(const PriorityCustomer& rhs)
      : Customer(rhs), priority_(rhs.priority_) {
    CallLog("PriorityCustomer copy constructor");
  }

  // Call copy assignment operator of base class
  PriorityCustomer& operator=(const PriorityCustomer& rhs) {
    CallLog("PriorityCustomer copy assignment operator");
    // Assign values ​​to base class members.
    Customer::operator=(rhs);
    this->priority_ = rhs.priority_;
    return *this;
  }

 private:
  int priority_;
};

}  // namespace effective
#endif