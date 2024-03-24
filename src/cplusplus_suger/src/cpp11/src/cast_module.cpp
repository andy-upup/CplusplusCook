#include "cast_module.h"

namespace cpp11 {

// const_cast: Remove constant attributes of pointer of reference
void ConstTest() {
    ////////////////////////////////////////////////
    // pointer
    int arr[4] = {1, 2, 3, 4};
    std::cout << "source array: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    const int* kparr = arr;
    int* parr = const_cast<int*>(kparr);
    for (int i = 0; i < 4; ++i) {
        parr[i] += 10;
    }

    std::cout << "target array: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    ////////////////////////////////////////////////
    // reference
    int val = 10;
    std::cout << "source val: " << val << std::endl;
    const int& kref = val;
    int& ref = const_cast<int&>(kref);
    ref = 100;
    std::cout << "target val: " << val << std::endl;
}

class Person {};
class Son : public Person {};

void StaticTest() {
    char str_a = 'c';
    int val = static_cast<int>(str_a);
    std::cout << "val: " << val << std::endl;

    const char kstr_b = 'c';
    char str_b = static_cast<char>(kstr_b);
    std::cout << "str_b: " << str_b << std::endl;
}

} // namespace cpp11