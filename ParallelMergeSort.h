#ifndef INC_3_LAB_PARALLELMERGESORT_H
#define INC_3_LAB_PARALLELMERGESORT_H

#include "ISort.h"

class ParallelMergeSort : public ISort {
public:
    explicit ParallelMergeSort(int depth);
    void sort(std::vector<int>& arr) override;
    bool isSorted(const std::vector<int>& arr) const override;

private:
    void merge(std::vector<int>& arr, int l, int m, int r);
    void parallelMergeSort(std::vector<int>& arr, int l, int r, int depth);
    void mergeSort(std::vector<int>& arr, int l, int r);

    int depth_;
};


#endif //INC_3_LAB_PARALLELMERGESORT_H
