#include <iostream>
#include <vector>

using namespace std;

/**
 * Helper function to swap two elements in the array
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * Partition function using Lomuto partition scheme
 * Places pivot element at its correct position and places all
 * smaller elements to left of pivot and all greater to right
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int partition(vector<int>& arr, int low, int high) {
    // Choose the rightmost element as pivot
    int pivot = arr[high];
    
    // Index of smaller element indicating the right position
    // of pivot found so far
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/**
 * Alternative partition function using Hoare partition scheme
 * More efficient in practice as it does fewer swaps on average
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int partitionHoare(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    
    while (true) {
        // Find leftmost element greater than or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);
        
        // Find rightmost element smaller than or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);
        
        // If elements crossed, partitioning is done
        if (i >= j)
            return j;
        
        swap(arr[i], arr[j]);
    }
}

/**
 * Main quick sort function implementing divide and conquer strategy
 * Time Complexity: Average O(n log n), Worst O(n²)
 * Space Complexity: O(log n) due to recursion stack
 */
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);
        
        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * Quick sort using Hoare partition scheme
 * Time Complexity: Average O(n log n), Worst O(n²)
 * Space Complexity: O(log n) due to recursion stack
 */
void quickSortHoare(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partitionHoare(arr, low, high);
        
        // Separately sort elements before and after partition
        quickSortHoare(arr, low, pi);
        quickSortHoare(arr, pi + 1, high);
    }
}

/**
 * Optimized quick sort with median-of-three pivot selection
 * This helps avoid worst-case performance on already sorted arrays
 */
int medianOfThree(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    
    if (arr[mid] < arr[low])
        swap(arr[low], arr[mid]);
    if (arr[high] < arr[low])
        swap(arr[low], arr[high]);
    if (arr[high] < arr[mid])
        swap(arr[mid], arr[high]);
    
    // Place median at the end
    swap(arr[mid], arr[high]);
    return high;
}

void quickSortOptimized(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Use median-of-three for pivot selection
        medianOfThree(arr, low, high);
        
        int pi = partition(arr, low, high);
        
        quickSortOptimized(arr, low, pi - 1);
        quickSortOptimized(arr, pi + 1, high);
    }
}

// Utility function to print vector
void printVector(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

// Driver code to test the implementation
int main() {
    // Test case 1: Basic array
    vector<int> arr1 = {10, 7, 8, 9, 1, 5};
    
    cout << "Original array 1: ";
    printVector(arr1);
    
    quickSort(arr1, 0, arr1.size() - 1);
    
    cout << "Sorted array 1 (Lomuto): ";
    printVector(arr1);
    
    cout << endl;
    
    // Test case 2: Array from merge sort example using Hoare partition
    vector<int> arr2 = {5, 2, 4, 6, 1, 3};
    
    cout << "Original array 2: ";
    printVector(arr2);
    
    quickSortHoare(arr2, 0, arr2.size() - 1);
    
    cout << "Sorted array 2 (Hoare): ";
    printVector(arr2);
    
    cout << endl;
    
    // Test case 3: Already sorted array (worst case for basic quick sort)
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    cout << "Original array 3 (sorted): ";
    printVector(arr3);
    
    quickSortOptimized(arr3, 0, arr3.size() - 1);
    
    cout << "Sorted array 3 (Optimized): ";
    printVector(arr3);
    
    cout << endl;
    
    // Test case 4: Reverse sorted array
    vector<int> arr4 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    cout << "Original array 4 (reverse sorted): ";
    printVector(arr4);
    
    quickSort(arr4, 0, arr4.size() - 1);
    
    cout << "Sorted array 4: ";
    printVector(arr4);
    
    return 0;
}