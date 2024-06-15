#ifndef INC_3_LAB_MERGE_SORT_PARALLEL_H
#define INC_3_LAB_MERGE_SORT_PARALLEL_H

#include <vector>

namespace merge_sort_parallel {
    void merge(std::vector<int>& arr, int l, int m, int r);
    void parallelMergeSort(std::vector<int>& arr, int l, int r, int depth);
    void mergeSort(std::vector<int>& arr, int l, int r);
    bool isSorted(const std::vector<int>& arr);
}

#endif //INC_3_LAB_MERGE_SORT_PARALLEL_H
