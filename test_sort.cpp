/**
 * @file MergeSortTest.cpp
 * @brief Unit tests for SequentialMergeSort and ParallelMergeSort classes.
 */

#include <gtest/gtest.h>
#include <vector>
#include <random> // Include for std::random_device, std::mt19937, std::uniform_int_distribution

#include "SequentialMergeSort.h"
#include "ParallelMergeSort.h"

/**
 * @brief Test case for handling an empty array with SequentialMergeSort.
 *
 * This test initializes a SequentialMergeSort object and sorts an empty array.
 * It then checks if the array remains sorted (trivially true for an empty array).
 */
TEST(MergeSortTest, HandlesEmptyArray) {
    SequentialMergeSort seqSorter;
    std::vector<int> arr;
    seqSorter.sort(arr);
    EXPECT_TRUE(seqSorter.isSorted(arr));
}

/**
 * @brief Test case for handling a single element array with SequentialMergeSort.
 *
 * This test initializes a SequentialMergeSort object and sorts a single-element array.
 * It then checks if the array is correctly sorted (trivially true for a single element).
 */
TEST(MergeSortTest, HandlesSingleElementArray) {
    SequentialMergeSort seqSorter;
    std::vector<int> arr = {1};
    seqSorter.sort(arr);
    EXPECT_TRUE(seqSorter.isSorted(arr));
}

/**
 * @brief Test case for handling a sorted array with SequentialMergeSort.
 *
 * This test initializes a SequentialMergeSort object and sorts a pre-sorted array.
 * It then checks if the array remains sorted.
 */
TEST(MergeSortTest, HandlesSortedArray) {
    SequentialMergeSort seqSorter;
    std::vector<int> arr = {1, 2, 3, 4, 5};
    seqSorter.sort(arr);
    EXPECT_TRUE(seqSorter.isSorted(arr));
}

/**
 * @brief Test case for handling an unsorted array with SequentialMergeSort.
 *
 * This test initializes a SequentialMergeSort object and sorts an unsorted array.
 * It then checks if the array becomes sorted after sorting.
 */
TEST(MergeSortTest, HandlesUnsortedArray) {
    SequentialMergeSort seqSorter;
    std::vector<int> arr = {5, 4, 3, 2, 1};
    seqSorter.sort(arr);
    EXPECT_TRUE(seqSorter.isSorted(arr));
}

/**
 * @brief Test case for handling a large random array with SequentialMergeSort.
 *
 * This test initializes a SequentialMergeSort object and sorts a large array
 * filled with random integers. It then checks if the array is correctly sorted.
 */
TEST(MergeSortTest, HandlesLargeArray) {
    const int N = 1000000;
    std::vector<int> arr(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    for (int i = 0; i < N; ++i) {
        arr[i] = dis(gen);
    }

    SequentialMergeSort seqSorter;
    seqSorter.sort(arr);
    EXPECT_TRUE(seqSorter.isSorted(arr));
}

/**
 * @brief Test case for handling a large random array with ParallelMergeSort.
 *
 * This test initializes a ParallelMergeSort object with a specified depth and
 * sorts a large array filled with random integers. It then checks if the array
 * is correctly sorted.
 *
 * @param depth The depth of parallelism for ParallelMergeSort.
 */
TEST(ParallelMergeSortTest, HandlesLargeArray) {
    const int N = 1000000;
    const int depth = 4;
    std::vector<int> arr(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    for (int i = 0; i < N; ++i) {
        arr[i] = dis(gen);
    }

    ParallelMergeSort parSorter(depth);
    parSorter.sort(arr);
    EXPECT_TRUE(parSorter.isSorted(arr));
}

/**
 * @brief Main function to run all tests.
 *
 * Initializes Google Test framework and runs all the test cases.
 *
 * @param argc Argument count.
 * @param argv Argument values.
 * @return Execution result.
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

