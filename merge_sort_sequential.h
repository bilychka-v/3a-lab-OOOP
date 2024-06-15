#ifndef INC_3_LAB_MERGE_SORT_SEQUENTIAL_H
#define INC_3_LAB_MERGE_SORT_SEQUENTIAL_H

#include <vector>

void merge(std::vector<int>& arr, int l, int m, int r);
void mergeSort(std::vector<int>& arr, int l, int r);
bool isSorted(const std::vector<int>& arr);

#endif //INC_3_LAB_MERGE_SORT_SEQUENTIAL_H
