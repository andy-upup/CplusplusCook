#include "insertion_sort.h"

// sort the previous part, 
// insert the followint number into the appropriate position in the sorting part
void InsertionSort(std::vector<int>& vec) {
    std::cout << __func__ << std::endl;
    if (vec.empty()) {
        std::cout << "Empty vec!" << std::endl;
        return;
    }
    const int size = vec.size();
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            if (vec[j] < vec[j - 1]) {
                int mid_val = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = mid_val;
            }
        }
    }
}