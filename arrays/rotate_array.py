"""
Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.

Approach:
- Use a three-step approach: reverse the entire array, then reverse the first k elements, 
  then reverse the remaining elements.
- This effectively rotates the array without using extra space.

Time Complexity: O(n)
Space Complexity: O(1)
"""

def rotate_array(nums, k):
    if not nums or len(nums) <= 1:
        return nums
    
    n = len(nums)
    k = k % n  # Handle case where k > n
    
    # Helper function to reverse a portion of the array
    def reverse(arr, start, end):
        while start < end:
            arr[start], arr[end] = arr[end], arr[start]
            start += 1
            end -= 1
    
    # Three-step reversal approach
    reverse(nums, 0, n - 1)      # Reverse the entire array
    reverse(nums, 0, k - 1)      # Reverse first k elements
    reverse(nums, k, n - 1)      # Reverse remaining elements
    
    return nums

# Test cases
if __name__ == "__main__":
    # Test case 1: Basic rotation
    print(rotate_array([1, 2, 3, 4, 5, 6, 7], 3))  # [5, 6, 7, 1, 2, 3, 4]
    
    # Test case 2: Rotation where k > array length
    print(rotate_array([1, 2, 3], 4))  # [3, 1, 2] (k = 4 % 3 = 1)
    
    # Test case 3: Empty array
    print(rotate_array([], 3))  # []
    
    # Test case 4: Single element array
    print(rotate_array([1], 5))  # [1]
    
    # Test case 5: Rotation by 0 steps
    print(rotate_array([1, 2, 3, 4], 0))  # [1, 2, 3, 4]