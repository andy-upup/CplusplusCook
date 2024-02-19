#ifndef SORT_H__
#define SORT_H__
#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& vec);
void HeapSort(std::vector<int>& vec);
void InsertionSort(std::vector<int>& vec);
void MergeSort(std::vector<int>& vec);
void QuickSort(std::vector<int>& vec);
void SelectionSort(std::vector<int>& vec);
void ShellSort(std::vector<int>& vec, const int gap);

#endif