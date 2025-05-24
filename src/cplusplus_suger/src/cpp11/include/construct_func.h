#ifndef CONSTRUCT_FUNC_H__
#define CONSTRUCT_FUNC_H__
#include <iostream>
#include <vector>

namespace cpp11 {

// Default copy-constructor only copies the member itself.
// For example, when it copies a pointer, they have the same value(
// The value of a pointer is an address).
// When it copies an array, they have the same array contents(
// But not the same array, addresses of the arraies are different).
class DefaultCopyClass {
 public:
  DefaultCopyClass(const int val, const std::string& str,
                   const std::vector<int>& vec)
      : val_(val), str_(str), vec_(vec) {
    ptr_ = new int[1];
    ptr_[0] = 10;
  }
  ~DefaultCopyClass() { delete[] ptr_; }
  int GetVal() { return val_; }
  std::string GetStr() { return str_; }
  std::vector<int> GetVec() { return vec_; }
  void PrintPtr() {
    std::cout << "ptr_(address) is: " << ptr_ << std::endl;
    std::cout << "ptr_(content) is: " << ptr_[0] << std::endl;
  }
  void InitArr(std::vector<int>& vec) {
    if (vec.size() != 5) {
      return;
    }
    for (int i = 0; i < 5; ++i) {
      arr_[i] = vec[i];
    }
  }
  void PrintArr() {
    std::cout << "arr_(address) is: " << arr_ << std::endl;
    std::cout << "arr_(array) is: ";
    for (int i = 0; i < 5; ++i) {
      std::cout << arr_[i] << " ";
    }
    std::cout << std::endl;
  }

 private:
  int val_;
  int arr_[5];
  int* ptr_;
  std::string str_;
  std::vector<int> vec_;
};

class Copyable {
 public:
  Copyable(int val = 10) : val_(val) { std::cout << "Construct." << std::endl; }
  Copyable(const Copyable& input) {
    val_ = input.val_;
    std::cout << "Copy-construct." << std::endl;
  }
  Copyable(const Copyable&& input) {
    val_ = input.val_;
    std::cout << "Move-construct." << std::endl;
  }
  void Print() { std::cout << "Hello World!" << std::endl; }

 private:
  int val_;
};

Copyable ReturnRvalue();
void TestDefaultCopyConstruct();

}  // namespace cpp11
#endif