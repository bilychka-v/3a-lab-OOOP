#ifndef INC_3_LAB_SEQUENTIALMERGESORT_H
#define INC_3_LAB_SEQUENTIALMERGESORT_H

#include "ISort.h"

class SequentialMergeSort : public ISort {
public:
    void sort(std::vector<int>& arr) override;
    bool isSorted(const std::vector<int>& arr) const override;

private:
    void merge(std::vector<int>& arr, int l, int m, int r);
    void mergeSort(std::vector<int>& arr, int l, int r);
};

#endif //INC_3_LAB_SEQUENTIALMERGESORT_H
