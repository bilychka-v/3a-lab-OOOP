//#include "googletest/googletest/include/gtest/gtest.h"
//#include "googletest/googletest/include/gtest/gtest-assertion-result.h"
//#include <vector>
//#include <random> // Include for std::random_device, std::mt19937, std::uniform_int_distribution
//
//#include "SequentialMergeSort.h"
//#include "ParallelMergeSort.h"
//
//// Define your test cases here
//
//TEST(MergeSortTest, HandlesEmptyArray) {
//SequentialMergeSort seqSorter;
//std::vector<int> arr;
//seqSorter.sort(arr);
//EXPECT_TRUE(seqSorter.isSorted(arr));
//}
//
//TEST(MergeSortTest, HandlesSingleElementArray) {
//SequentialMergeSort seqSorter;
//std::vector<int> arr = {1};
//seqSorter.sort(arr);
//EXPECT_TRUE(seqSorter.isSorted(arr));
//}
//
//TEST(MergeSortTest, HandlesSortedArray) {
//SequentialMergeSort seqSorter;
//std::vector<int> arr = {1, 2, 3, 4, 5};
//seqSorter.sort(arr);
//EXPECT_TRUE(seqSorter.isSorted(arr));
//}
//
//TEST(MergeSortTest, HandlesUnsortedArray) {
//SequentialMergeSort seqSorter;
//std::vector<int> arr = {5, 4, 3, 2, 1};
//seqSorter.sort(arr);
//EXPECT_TRUE(seqSorter.isSorted(arr));
//}
//
//TEST(MergeSortTest, HandlesLargeArray) {
//const int N = 1000000;
//std::vector<int> arr(N);
//std::random_device rd;
//std::mt19937 gen(rd());
//std::uniform_int_distribution<> dis(1, 1000000);
//for (int i = 0; i < N; ++i) {
//arr[i] = dis(gen);
//}
//
//SequentialMergeSort seqSorter;
//seqSorter.sort(arr);
//EXPECT_TRUE(seqSorter.isSorted(arr));
//}
//
//TEST(ParallelMergeSortTest, HandlesLargeArray) {
//const int N = 1000000;
//const int depth = 4;
//std::vector<int> arr(N);
//std::random_device rd;
//std::mt19937 gen(rd());
//std::uniform_int_distribution<> dis(1, 1000000);
//for (int i = 0; i < N; ++i) {
//arr[i] = dis(gen);
//}
//
//ParallelMergeSort parSorter(depth);
//parSorter.sort(arr);
//EXPECT_TRUE(parSorter.isSorted(arr));
//}
//
//// Main function to run all tests
//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
