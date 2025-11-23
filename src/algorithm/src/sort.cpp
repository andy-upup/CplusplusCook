#include "sort.h"

namespace algo {

// move large numbers to the back
void BubbleSort(std::vector<int> &vec) {
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

///////////////////////////////////////////////////////////////////////
static void AdjustHeap(std::vector<int> &vec, int size, int index) {
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

// up
static void HeapInsert(std::vector<int> &vec, int index) {
  while (vec[index] > vec[(index - 1) / 2]) {
    std::swap(vec[index], vec[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

// we can use Heapify to construct a big root heap
// down
static void Heapify(std::vector<int> &vec, int index, int heap_size) {
  int left = 2 * index + 1;
  while (left < heap_size) {
    int largest =
        left + 1 < heap_size && vec[left + 1] > vec[left] ? left + 1 : left;
    largest = vec[largest] > vec[index] ? largest : index;
    if (largest == index) {
      break;
    }
    std::swap(vec[index], vec[largest]);
    index = largest;
    left = 2 * index + 1;
  }
}

void HeapSort(std::vector<int> &vec) {
  if (vec.size() < 2) {
    return;
  }
  for (int i = 0; i < vec.size(); ++i) {
    // heap insert from 0 to size - 1
    // construct the 1st big root heap
    HeapInsert(vec, i);
  }
  int heap_size = vec.size();
  std::swap(vec[0], vec[--heap_size]);

  while (heap_size > 0) {
    Heapify(vec, 0, heap_size);
    std::swap(vec[0], vec[--heap_size]);
  }
}

///////////////////////////////////////////////////////////////////////
// sort the previous part,
// insert the followint number into the appropriate position in the sorting part
void InsertionSort(std::vector<int> &vec) {
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

///////////////////////////////////////////////////////////////////////
static void MergeSort(std::vector<int> &vec, int start, int mid, int end) {
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

static void MergeSort(std::vector<int> &vec, int start, int end) {
  if (start >= end) {
    return;
  }
  const int mid = (start + end) >> 1;
  MergeSort(vec, start, mid);
  MergeSort(vec, mid + 1, end);
  MergeSort(vec, start, mid, end);
}

void MergeSort(std::vector<int> &vec) {
  std::cout << __func__ << std::endl;
  if (vec.empty()) {
    std::cout << "Empty vec!" << std::endl;
    return;
  }
  const int size = vec.size();
  MergeSort(vec, 0, size - 1);
}

///////////////////////////////////////////////////////////////////////
static void QuickSort(std::vector<int> &vec, const int start, const int end) {
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
  }
  vec[left] = key;
  QuickSort(vec, start, left - 1);
  QuickSort(vec, left + 1, end);
}

void QuickSort(std::vector<int> &vec) {
  std::cout << __func__ << std::endl;
  if (vec.empty()) {
    std::cout << "Empty vec!" << std::endl;
    return;
  }
  const int size = vec.size();
  QuickSort(vec, 0, size - 1);
}

///////////////////////////////////////////////////////////////////////
// move small numbers to the front
void SelectionSort(std::vector<int> &vec) {
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

///////////////////////////////////////////////////////////////////////
// compare two numbers at each gap, like insertion sort
void ShellSort(std::vector<int> &vec, const int init_gap) {
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

}  // namespace algo