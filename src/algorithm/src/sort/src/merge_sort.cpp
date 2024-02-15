#include "merge_sort.h"

static void MergeSort(std::vector<int>& vec, int start, int mid, int end) {
    int size = end - start + 1;
    std::vector<int> mid_vec(size, 0);
    int i = 0;
    int left = start;
    int right = mid + 1;
    while (left <= mid && right <= end) {
        mid_vec[i++] = (vec[left] < vec[right] ? vec[left++] : vec[right++]);
    }
    while (left <= mid) {
        mid_vec[i++] = vec[left++];
    }
    while (right <= end) {
        mid_vec[i++] = vec[right++];
    }
    i = 0;
    while (start <= end) {
        vec[start++] = mid_vec[i++];
    }
}

static void MergeSort(std::vector<int>& vec, int start, int end) {
    if (start >= end) {
        return;
    }
    const int mid = (start + end) >> 1;
    MergeSort(vec, start, mid);
    MergeSort(vec, mid + 1, end);
    MergeSort(vec, start, mid, end);
}

void MergeSort(std::vector<int>& vec) {
    std::cout << __func__ << std::endl;
    if (vec.empty()) {
        std::cout << "Empty vec!" << std::endl;
        return;
    }
    const int size = vec.size();
    MergeSort(vec, 0, size - 1);
}