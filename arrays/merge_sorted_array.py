"""
Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note: nums1 has enough space at the end to hold additional elements from nums2.

Approach:
- Start from the end of both arrays and the end of the merged array.
- Compare elements from the end and place the larger one at the end of nums1.
- Continue until all elements from nums2 are placed.

Time Complexity: O(n + m) where n and m are the sizes of nums1 and nums2
Space Complexity: O(1) as we're doing it in-place
"""

def merge_sorted_array(nums1, m, nums2, n):
    # Set pointers to the end of both arrays and the end of the merged array
    """
    Merge the first m elements of nums1 with the first n elements of nums2 into nums1 in sorted order.
    
    Parameters:
        nums1 (list[int]): Destination list with length at least m + n; first m entries are the valid sorted elements and remaining space is available for merging.
        m (int): Number of valid sorted elements initially in nums1.
        nums2 (list[int]): Source list containing n sorted elements to merge into nums1.
        n (int): Number of valid sorted elements in nums2.
    
    Returns:
        list[int]: nums1 after merging, containing m + n sorted elements.
    """
    p1 = m - 1     # Pointer for nums1
    p2 = n - 1     # Pointer for nums2
    p = m + n - 1  # Pointer for the merged array position

    # While there are elements in both arrays to compare
    while p1 >= 0 and p2 >= 0:
        if nums1[p1] > nums2[p2]:
            nums1[p] = nums1[p1]
            p1 -= 1
        else:
            nums1[p] = nums2[p2]
            p2 -= 1
        p -= 1
    
    # If there are remaining elements in nums2, add them to nums1
    # (remaining elements in nums1 are already in their correct position)
    while p2 >= 0:
        nums1[p] = nums2[p2]
        p2 -= 1
        p -= 1
    
    return nums1

# Test cases
if __name__ == "__main__":
    # Test case 1: Basic merge
    nums1 = [1, 2, 3, 0, 0, 0]
    m = 3
    nums2 = [2, 5, 6]
    n = 3
    print(merge_sorted_array(nums1, m, nums2, n))  # [1, 2, 2, 3, 5, 6]
    
    # Test case 2: When nums1 is empty
    nums1 = [0, 0, 0]
    m = 0
    nums2 = [1, 2, 3]
    n = 3
    print(merge_sorted_array(nums1, m, nums2, n))  # [1, 2, 3]
    
    # Test case 3: When nums2 is empty
    nums1 = [1, 2, 3]
    m = 3
    nums2 = []
    n = 0
    print(merge_sorted_array(nums1, m, nums2, n))  # [1, 2, 3]
    
    # Test case 4: With negative numbers
    nums1 = [-1, 0, 0, 3, 0, 0, 0]
    m = 4
    nums2 = [-3, -2, 5]
    n = 3
    print(merge_sorted_array(nums1, m, nums2, n))  # [-3, -2, -1, 0, 0, 3, 5]
    
    # Test case 5: With duplicates
    nums1 = [1, 1, 2, 0, 0, 0]
    m = 3
    nums2 = [1, 2, 3]
    n = 3
    print(merge_sorted_array(nums1, m, nums2, n))  # [1, 1, 1, 2, 2, 3]