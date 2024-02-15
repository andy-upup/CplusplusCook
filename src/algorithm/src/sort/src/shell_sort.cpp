#include "shell_sort.h"

// compare two numbers at each gap, like insertion sort
void ShellSort(std::vector<int>& vec, const int init_gap) {
    std::cout << __func__ << std::endl;
    if (vec.empty()) {
        std::cout << "Empty vec!" << std::endl;
        return;
    }
    const int size = vec.size();
    for (int gap = init_gap; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            for (int j = i; j > gap - 1; j -= gap) {
                if (vec[j - gap] > vec[j]) {
                    int mid_val = vec[j - gap];
                    vec[j - gap] = vec[j];
                    vec[j] = mid_val;
                }
            }
        }
    }
}