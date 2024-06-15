/**
 * @file main.cpp
 * @brief Demonstrates sequential and parallel merge sort algorithms on a large array.
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random> // Include for std::random_device, std::mt19937, std::uniform_int_distribution
#include "SequentialMergeSort.h"
#include "ParallelMergeSort.h"
#include <thread> // Include for std::thread and std::thread::hardware_concurrency()

/**
 * @brief Main function to demonstrate sequential and parallel merge sort algorithms.
 *
 * This function initializes a large random array, performs sorting using both SequentialMergeSort
 * and ParallelMergeSort, measures the execution time for each sorting method, and checks if the
 * arrays are sorted correctly.
 *
 * @return 0 on successful execution.
 */
int main() {
    const int N = 1000000; // Size of the array
    const int depth = std::thread::hardware_concurrency(); // Depth for parallelization

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

    SequentialMergeSort seqSorter;
    auto start_seq = std::chrono::high_resolution_clock::now();
    seqSorter.sort(arr);
    auto end_seq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_seq = end_seq - start_seq;
    std::cout << "Time taken by sequential merge sort: " << duration_seq.count() << " seconds\n";

    if (seqSorter.isSorted(arr)) {
        std::cout << "Sequential sort: Array is sorted.\n";
    } else {
        std::cout << "Sequential sort: Array is not sorted.\n";
    }

    ParallelMergeSort parSorter(depth);
    auto start_par = std::chrono::high_resolution_clock::now();
    parSorter.sort(arr_copy);
    auto end_par = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_par = end_par - start_par;
    std::cout << "Time taken by parallel merge sort: " << duration_par.count() << " seconds\n";

    if (parSorter.isSorted(arr_copy)) {
        std::cout << "Parallel sort: Array is sorted.\n";
    } else {
        std::cout << "Parallel sort: Array is not sorted.\n";
    }

    return 0;
}



