/**
 * @file ISort.h
 * @brief Definition of the sorting interface.
 */

#ifndef INC_3_LAB_ISORT_H
#define INC_3_LAB_ISORT_H

#include <vector>

/**
 * @class ISort
 * @brief Abstract class for implementing sorting algorithms.
 */
class ISort {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~ISort() = default;

    /**
     * @brief Virtual function to sort an array.
     * @param arr Vector of integers to be sorted.
     */
    virtual void sort(std::vector<int>& arr) = 0;

    /**
     * @brief Virtual function to check if the array is sorted.
     * @param arr Constant vector of integers to be checked.
     * @return true if the array is sorted, otherwise false.
     */
    virtual bool isSorted(const std::vector<int>& arr) const = 0;
};

#endif //INC_3_LAB_ISORT_H
