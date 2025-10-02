"""
Problem: Merge Sort
Description: Implement merge sort algorithm to sort an array in ascending order.

Time Complexity: O(n log n)
Space Complexity: O(n)

Approach:
- Use the recursive divide-and-conquer strategy.
- Divide the array into halves until single elements remain.
- Merge the sorted halves into a fully sorted array.
"""

def merge_sort(arr):
    # Base case: if array has 1 or fewer elements, it's already sorted
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2

    # Recursively sort both halves
    left_half = merge_sort(arr[:mid])
    right_half = merge_sort(arr[mid:])

    # Merge the sorted halves
    return merge(left_half, right_half)


def merge(left, right):
    merged = []
    i = j = 0

    # Merge while elements remain in both arrays
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    # Append remaining elements
    merged.extend(left[i:])
    merged.extend(right[j:])

    return merged


# Test cases
if __name__ == "__main__":
    arr = [5, 2, 4, 6, 1, 3]
    print("Original array:", arr)
    print("Sorted array:", merge_sort(arr))
