#include <iostream>
#include <vector>

using namespace std;

/**
 * Helper function to merge two sorted subarrays
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    // Create temp vectors
    vector<int> L(n1);
    vector<int> R(n2);
 
    // Copy data to temp vectors
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
 
    // Merge the temp vectors back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/**
 * Main merge sort function implementing divide and conquer strategy
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find middle point
        int mid = left + (right - left) / 2;
 
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
 
        // Merge the sorted halves
        merge(arr, left, mid, right);
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
    // Test case from the issue
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    
    cout << "Original array: ";
    printVector(arr);
 
    mergeSort(arr, 0, arr.size() - 1);
 
    cout << "Sorted array: ";
    printVector(arr);
 
    return 0;
}
