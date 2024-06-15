/**
 * @file ParallelMergeSort.h
 * @brief Definition of the ParallelMergeSort class.
 */

#ifndef INC_3_LAB_PARALLELMERGESORT_H
#define INC_3_LAB_PARALLELMERGESORT_H

#include "ISort.h"

/**
 * @class ParallelMergeSort
 * @brief Class for implementing parallel merge sort algorithm.
 */
class ParallelMergeSort : public ISort {
public:
    /**
     * @brief Constructor for ParallelMergeSort.
     * @param depth The depth of parallelism.
     */
    explicit ParallelMergeSort(int depth);

    /**
     * @brief Sorts the given array using parallel merge sort algorithm.
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
     * @brief Sorts the array using parallel merge sort algorithm.
     * @param arr Vector of integers to be sorted.
     * @param l Left index.
     * @param r Right index.
     * @param depth Current depth of recursion.
     */
    void parallelMergeSort(std::vector<int>& arr, int l, int r, int depth);

    /**
     * @brief Sorts the array using merge sort algorithm.
     * @param arr Vector of integers to be sorted.
     * @param l Left index.
     * @param r Right index.
     */
    void mergeSort(std::vector<int>& arr, int l, int r);

    /**
     * @brief The depth of parallelism.
     */
    int depth_;
};

#endif //INC_3_LAB_PARALLELMERGESORT_H
