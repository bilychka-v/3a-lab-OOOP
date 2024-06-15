// File: main.cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "merge_sort_sequential.h"
#include "merge_sort_parallel.h"

int main() {
    const int N = 1000000; // Size of the array
    const int depth = 4; // Depth for parallelization

    std::vector<int> arr(N);
    std::vector<int> arr_copy(N);

    // Generate random array
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    for (int i = 0; i < N; ++i) {
        arr[i] = dis(gen);
    }
    arr_copy = arr;

    // Sequential Merge Sort
    auto start_seq = std::chrono::high_resolution_clock::now();
    merge_sort_sequential::mergeSort(arr, 0, N - 1);
    auto end_seq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_seq = end_seq - start_seq;
    std::cout << "Time taken by sequential merge sort: " << duration_seq.count() << " seconds\n";

    if (merge_sort_sequential::isSorted(arr)) {
        std::cout << "Sequential sort: Array is sorted.\n";
    } else {
        std::cout << "Sequential sort: Array is not sorted.\n";
    }

    // Parallel Merge Sort
    auto start_par = std::chrono::high_resolution_clock::now();
    merge_sort_parallel::parallelMergeSort(arr_copy, 0, N - 1, depth);
    auto end_par = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_par = end_par - start_par;
    std::cout << "Time taken by parallel merge sort: " << duration_par.count() << " seconds\n";

    if (merge_sort_parallel::isSorted(arr_copy)) {
        std::cout << "Parallel sort: Array is sorted.\n";
    } else {
        std::cout << "Parallel sort: Array is not sorted.\n";
    }

    return 0;
}



