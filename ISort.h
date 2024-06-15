#ifndef INC_3_LAB_ISORT_H
#define INC_3_LAB_ISORT_H

#include <vector>

class ISort {
public:
    virtual ~ISort() = default;
    virtual void sort(std::vector<int>& arr) = 0;
    virtual bool isSorted(const std::vector<int>& arr) const = 0;
};


#endif //INC_3_LAB_ISORT_H
