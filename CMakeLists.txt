cmake_minimum_required(VERSION 3.26)
project(3_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(3_lab
        main.cpp
        ISort.h
        SequentialMergeSort.cpp
        SequentialMergeSort.h
        ParallelMergeSort.cpp
        ParallelMergeSort.h
)

# Include FetchContent module
include(FetchContent)

# Download and include GoogleTest
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Prevent GoogleTest from overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make GoogleTest available
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add test executable
add_executable(test_sort
        test_sort.cpp
        ISort.h
        SequentialMergeSort.cpp
        SequentialMergeSort.h
        ParallelMergeSort.cpp
        ParallelMergeSort.h
)

# Link GoogleTest to test_sort executable
target_link_libraries(test_sort gtest gtest_main)

# Add test to CTest
add_test(NAME test_sort COMMAND test_sort)

