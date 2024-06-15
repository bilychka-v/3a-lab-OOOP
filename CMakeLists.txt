cmake_minimum_required(VERSION 3.26)
project(3_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(3_lab
        main.cpp
        ISort.cpp
        ISort.h
        SequentialMergeSort.cpp
        SequentialMergeSort.h
        ParallelMergeSort.cpp
        ParallelMergeSort.h
        test_sort.cpp
)

# Add Google Test
add_subdirectory(googletest)
include_directories(googletest/googletest/include/gtest)

# Define the test executable and link libraries
add_executable(runTest
        test_sort.cpp
        SequentialMergeSort.cpp
        ParallelMergeSort.cpp
)

target_link_libraries(runTest
        gtest
        gtest_main
        pthread
)

# Enable testing
enable_testing()
add_test(NAME runTest COMMAND runTest)
