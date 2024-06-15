/**
 * @file SequentialMergeSort.h
 * @brief Definition of the SequentialMergeSort class.
 */

#ifndef INC_3_LAB_SEQUENTIALMERGESORT_H
#define INC_3_LAB_SEQUENTIALMERGESORT_H

#include "ISort.h"

/**
 * @class SequentialMergeSort
 * @brief Class for implementing sequential merge sort algorithm.
 */
class SequentialMergeSort : public ISort {
public:
    /**
     * @brief Sorts the given array using sequential merge sort algorithm.
     * @param arr Vector of integers to be sorted.
     */
    void sort(std::vector<int>& arr) override;

    /**
     * @brief Checks if the given array is sorted.
     * @param arr Constant vector of integers to be checked.
     * @return true if the array is sorted, otherwise false.
     */
    bool isSorted(const std::vector<int>& arr) const override;

private:
    /**
     * @brief Merges two subarrays of arr.
     * @param arr Vector of integers to be merged.
     * @param l Left index.
     * @param m Middle index.
     * @param r Right index.
     */
    void merge(std::vector<int>& arr, int l, int m, int r);

    /**
     * @brief Sorts the array using merge sort algorithm.
     * @param arr Vector of integers to be sorted.
     * @param l Left index.
     * @param r Right index.
     */
    void mergeSort(std::vector<int>& arr, int l, int r);
};

#endif //INC_3_LAB_SEQUENTIALMERGESORT_H
