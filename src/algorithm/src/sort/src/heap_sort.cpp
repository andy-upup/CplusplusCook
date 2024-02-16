#include "heap_sort.h"

static void AdjustHeap(std::vector<int>& vec, int size, int index) {
    const int left = 2 * index + 1;
    const int right = 2 * index + 2;
    int max_index = index;
    if (left < size && vec[max_index] < vec[left]) {
        max_index = left;
    }
    if (right < size && vec[max_index] < vec[right]) {
        max_index = right;
    }
    if (max_index != index) {
        std::swap(vec[max_index], vec[index]);
        AdjustHeap(vec, size, max_index);
    }
}

void HeapSort(std::vector<int>& vec, int size) {
    // if i = size / 2 - 1, 
    // left = 2 * i + 1 = size - 1,
    // right = 2 * i + 2 = size
    // build large root heap
    for (int i = size / 2 - 1; i >= 0; --i) {
        // build heap from bottom up
        AdjustHeap(vec, size, i);
    }
    for (int i = size - 1; i >= 1; --i) {
        std::swap(vec[0], vec[i]);
        // size is i, size is decreasing
        AdjustHeap(vec, i, 0);
    }
}

void HeapSort(std::vector<int>& vec) {
    std::cout << __func__ << std::endl;
    if (vec.empty()) {
        std::cout << "Empty vec!" << std::endl;
        return;
    }
    const int size = vec.size();
    HeapSort(vec, size);
}