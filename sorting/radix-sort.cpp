#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Helper function to get the maximum value in the array
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int getMax(const vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    return *max_element(arr.begin(), arr.end());
}

/**
 * Counting sort function used by radix sort for sorting by digit
 * Time Complexity: O(n + k) where k is the range of digit (0-9)
 * Space Complexity: O(n + k)
 */
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);  // Output array
    vector<int> count(10, 0);  // Count array for digits 0-9
    
    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

/**
 * Main radix sort function implementing LSD (Least Significant Digit) approach
 * Time Complexity: O(d * (n + k)) where d is the number of digits, n is the number of elements, k is the range (10 for decimal)
 * Space Complexity: O(n + k)
 */
void radixSort(vector<int>& arr) {
    // Find the maximum number to know number of digits
    int maxNum = getMax(arr);
    
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
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
    vector<int> arr1 = {170, 45, 75, 90, 2, 802, 24, 66};
    
    cout << "Original array 1: ";
    printVector(arr1);
    
    radixSort(arr1);
    
    cout << "Sorted array 1: ";
    printVector(arr1);
    
    cout << endl;
    
    // Test case 2: Array from merge sort example
    vector<int> arr2 = {5, 2, 4, 6, 1, 3};
    
    cout << "Original array 2: ";
    printVector(arr2);
    
    radixSort(arr2);
    
    cout << "Sorted array 2: ";
    printVector(arr2);
    
    cout << endl;
    
    // Test case 3: Array with single digit numbers
    vector<int> arr3 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    
    cout << "Original array 3: ";
    printVector(arr3);
    
    radixSort(arr3);
    
    cout << "Sorted array 3: ";
    printVector(arr3);
    
    return 0;
}