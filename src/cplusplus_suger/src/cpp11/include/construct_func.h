#ifndef CONSTRUCT_FUNC_H__
#define CONSTRUCT_FUNC_H__
#include <iostream>
#include <vector>

namespace cpp11 {

class DefaultCopy {
 public:
    DefaultCopy(const int val, const std::string &str, const std::vector<int> &vec) :
        val_(val), str_(str), vec_(vec) {}
    int GetVal() {
        return val_;
    }
    std::string GetStr() {
        return str_;
    }
    std::vector<int> GetVec() {
        return vec_;
    }
 private:
    int val_;
    std::string str_;
    std::vector<int> vec_;
};

} // namespace cpp11
#endif