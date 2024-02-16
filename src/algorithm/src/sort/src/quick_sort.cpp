#include "quick_sort.h"

static void QuickSort(std::vector<int>& vec, const int start, const int end) {
    if (start >= end) {
        return;
    }
    int left = start;
    int right = end;
    const int key = vec[start];
    while (left < right) {
        while (left < right && key < vec[right]) {
            --right;
        }
        if (left < right) {
            vec[left++] = vec[right];
        }
        while (left < right && vec[left] <= key) {
            ++left;
        }
        if (left < right) {
            vec[right--] = vec[left];
        }
        vec[left] = key;
        QuickSort(vec, start, left - 1);
        QuickSort(vec, left + 1, end);
    }
}

void QuickSort(std::vector<int>& vec) {
    std::cout << __func__ << std::endl;
    if (vec.empty()) {
        std::cout << "Empty vec!" << std::endl;
        return;
    }
    const int size = vec.size();
    QuickSort(vec, 0, size - 1);
}