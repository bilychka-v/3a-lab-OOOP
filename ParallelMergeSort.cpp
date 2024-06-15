// File: ParallelMergeSort.cpp
#include "ParallelMergeSort.h"
#include <thread>

ParallelMergeSort::ParallelMergeSort(int depth) : depth_(depth) {}

void ParallelMergeSort::merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void ParallelMergeSort::parallelMergeSort(std::vector<int>& arr, int l, int r, int depth) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    if (depth > 0) {
        std::thread t1(&ParallelMergeSort::parallelMergeSort, this, std::ref(arr), l, m, depth - 1);
        std::thread t2(&ParallelMergeSort::parallelMergeSort, this, std::ref(arr), m + 1, r, depth - 1);
        t1.join();
        t2.join();
    } else {
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
    }
    merge(arr, l, m, r);
}

void ParallelMergeSort::mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void ParallelMergeSort::sort(std::vector<int>& arr) {
    parallelMergeSort(arr, 0, arr.size() - 1, depth_);
}

bool ParallelMergeSort::isSorted(const std::vector<int>& arr) const {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
