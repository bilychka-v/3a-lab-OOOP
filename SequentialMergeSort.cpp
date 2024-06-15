/**
 * @file SequentialMergeSort.cpp
 * @brief Implementation of the SequentialMergeSort class.
 */

#include "SequentialMergeSort.h"

/**
 * @brief Merges two subarrays of arr.
 * @param arr Vector of integers to be merged.
 * @param l Left index.
 * @param m Middle index.
 * @param r Right index.
 */
void SequentialMergeSort::merge(std::vector<int>& arr, int l, int m, int r) {
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

/**
 * @brief Sorts the array using merge sort algorithm.
 * @param arr Vector of integers to be sorted.
 * @param l Left index.
 * @param r Right index.
 */
void SequentialMergeSort::mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

/**
 * @brief Sorts the given array using sequential merge sort algorithm.
 * @param arr Vector of integers to be sorted.
 */
void SequentialMergeSort::sort(std::vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

/**
 * @brief Checks if the given array is sorted.
 * @param arr Constant vector of integers to be checked.
 * @return true if the array is sorted, otherwise false.
 */
bool SequentialMergeSort::isSorted(const std::vector<int>& arr) const {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
