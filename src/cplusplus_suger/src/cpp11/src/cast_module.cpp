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

} // namespace cpp11