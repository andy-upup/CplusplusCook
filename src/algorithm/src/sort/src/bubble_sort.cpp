#include "bubble_sort.h"

// move large numbers to the back
void BubbleSort(std::vector<int>& vec) {
    std::cout << __func__ << std::endl;
    if (vec.empty()) {
        std::cout << "Empty vec!" << std::endl;
        return;
    }
    const int size = vec.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (vec[j] > vec[j + 1]) {
                int mid_val = vec[j + 1];
                vec[j + 1] = vec[j];
                vec[j] = mid_val;
            }
        }
    }
}