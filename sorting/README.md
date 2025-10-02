# Merge Sort Implementation

## Description
This directory contains an efficient implementation of the Merge Sort algorithm, a stable sorting algorithm that uses the divide-and-conquer strategy.

## Algorithm Overview
Merge Sort works by:
1. Dividing the unsorted array into n subarrays, each containing one element
2. Repeatedly merging subarrays to produce new sorted subarrays
3. Finally merging all subarrays into one sorted array

## Complexity Analysis
- **Time Complexity**: 
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n log n)
- **Space Complexity**: O(n)
- **Stability**: Yes (maintains relative order of equal elements)

## Implementation Details
The implementation is available in C++ using STL vectors for dynamic array manipulation.

### Key Functions
1. `merge()`: Merges two sorted subarrays into a single sorted array
2. `mergeSort()`: Main recursive function that implements the divide-and-conquer strategy

## Test Cases

### Test Case 1: Basic Sorting
```cpp
Input: [5, 2, 4, 6, 1, 3]
Expected Output: [1, 2, 3, 4, 5, 6]
```

### Test Case 2: Array with Duplicate Elements
```cpp
Input: [4, 2, 4, 1, 3, 2]
Expected Output: [1, 2, 2, 3, 4, 4]
```

### Test Case 3: Already Sorted Array
```cpp
Input: [1, 2, 3, 4, 5, 6]
Expected Output: [1, 2, 3, 4, 5, 6]
```

### Test Case 4: Reverse Sorted Array
```cpp
Input: [6, 5, 4, 3, 2, 1]
Expected Output: [1, 2, 3, 4, 5, 6]
```

### Test Case 5: Array with Single Element
```cpp
Input: [1]
Expected Output: [1]
```

### Test Case 6: Empty Array
```cpp
Input: []
Expected Output: []
```

## Usage Example
```cpp
#include <vector>
MergeSort ms;
std::vector<int> arr = {5, 2, 4, 6, 1, 3};
ms.mergeSort(arr, 0, arr.size() - 1);
```

## Running Tests
To run the test cases:
1. Compile the C++ file:
   ```bash
   g++ merge-sort.cpp -o merge_sort
   ```
2. Execute the program:
   ```bash
   ./merge_sort
   ```

## Contributing
Feel free to contribute to this implementation by:
1. Adding more test cases
2. Optimizing the code
3. Improving documentation
4. Adding implementations in other languages

## Last Updated
2025-10-02 08:36:27 UTC by @Harshnot789
