/*
Problem: Merge Sort
Description: Implement merge sort algorithm to sort an array in ascending order.

Time Complexity: O(n log n)
Space Complexity: O(n)

Approach:
- Use divide and conquer: split the array into halves, recursively sort them, and merge.
- Implement merging using temporary vectors for simplicity.
*/

#include <bits/stdc++.h>
using namespace std;

// Merge two halves of the array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Recursive merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
