"""
Kadane's Algorithm for Maximum Subarray Sum

This algorithm finds the maximum sum of a contiguous subarray within a given array.
It uses dynamic programming approach with O(n) time complexity and O(1) space complexity.

Time Complexity: O(n)
Space Complexity: O(1)
"""

def kadane_algorithm(arr):
    """
    Find the maximum sum of contiguous subarray using Kadane's algorithm
    
    Args:
        arr: List of integers (can contain negative numbers)
        
    Returns:
        int: Maximum sum of contiguous subarray
    """
    if not arr:
        return 0
    
    max_current = max_global = arr[0]
    
    for i in range(1, len(arr)):
        # Either extend the existing subarray or start a new one
        max_current = max(arr[i], max_current + arr[i])
        # Update global maximum if current is better
        max_global = max(max_global, max_current)
    
    return max_global

def kadane_with_indices(arr):
    """
    Kadane's algorithm that also returns the start and end indices
    
    Args:
        arr: List of integers
        
    Returns:
        tuple: (max_sum, start_index, end_index)
    """
    if not arr:
        return 0, -1, -1
    
    max_sum = float('-inf')
    current_sum = 0
    start = 0
    end = 0
    temp_start = 0
    
    for i in range(len(arr)):
        current_sum += arr[i]
        
        if current_sum > max_sum:
            max_sum = current_sum
            start = temp_start
            end = i
        
        if current_sum < 0:
            current_sum = 0
            temp_start = i + 1
    
    return max_sum, start, end

def kadane_all_negative(arr):
    """
    Modified Kadane's for arrays with all negative numbers
    
    Args:
        arr: List of integers
        
    Returns:
        int: Maximum element (least negative)
    """
    if not arr:
        return 0
    
    # If all numbers are negative, return the maximum element
    if all(x < 0 for x in arr):
        return max(arr)
    
    return kadane_algorithm(arr)

# Test cases
if __name__ == "__main__":
    # Test case 1: Mixed positive and negative
    test1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    result1 = kadane_algorithm(test1)
    max_sum, start, end = kadane_with_indices(test1)
    print(f"Array: {test1}")
    print(f"Maximum subarray sum: {result1}")
    print(f"Subarray indices: [{start}, {end}]")
    print(f"Subarray: {test1[start:end+1]}")
    print()
    
    # Test case 2: All negative numbers
    test2 = [-5, -2, -8, -1, -4]
    result2 = kadane_all_negative(test2)
    print(f"Array: {test2}")
    print(f"Maximum subarray sum: {result2}")
    print()
    
    # Test case 3: All positive numbers
    test3 = [1, 2, 3, 4, 5]
    result3 = kadane_algorithm(test3)
    print(f"Array: {test3}")
    print(f"Maximum subarray sum: {result3}")
    print()
    
    # Test case 4: Single element
    test4 = [42]
    result4 = kadane_algorithm(test4)
    print(f"Array: {test4}")
    print(f"Maximum subarray sum: {result4}")