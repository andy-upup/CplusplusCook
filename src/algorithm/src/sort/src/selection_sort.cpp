#include "selection_sort.h"

// move small numbers to the front
void SelectionSort(std::vector<int>& vec) {
    std::cout << __func__ << std::endl;
    if (vec.empty()) {
        std::cout << "Empty vec!" << std::endl;
        return;
    }
    const int size = vec.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (vec[j] > vec[i]) {
                int mid_val = vec[j];
                vec[j] = vec[i];
                vec[i] = mid_val;
            }
        }
    }
}