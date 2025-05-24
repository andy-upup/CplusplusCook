#ifndef HEAP_MODULE_H__
#define HEAP_MODULE_H__
#include <algorithm>
#include <iostream>
#include <vector>

namespace cpp11 {

void TestMaxHeap(std::vector<int>& vec);
void TestMinHeap(std::vector<int>& vec);
void TestMaxHeap(std::vector<std::pair<int, int>>& vec);

}  // namespace cpp11
#endif