def two_sum(nums: list[int], target: int) -> list[int]:
    """
    Finds two numbers in a list that add up to a target value.

    This optimal solution uses a hash map to store numbers we've seen and their indices.
    It iterates through the list once, achieving O(n) time complexity and O(n) space complexity.
    """
    # Hash map to store {number: index}
    num_map = {}
    
    # Enumerate through the list to get both index and value
    for i, num in enumerate(nums):
        # Calculate the complement needed
        complement = target - num
        
        # If the complement exists in our map, we've found the solution
        if complement in num_map:
            return [num_map[complement], i]
            
        # Otherwise, add the current number and its index to the map
        num_map[num] = i
        
    # If no solution is found, return an empty list
    return []

# --- Test Cases ---
# Input: nums = [2, 7, 11, 15], target = 9
# Output: [0, 1]
print(two_sum([2, 7, 11, 15], 9))

# Input: nums = [3, 2, 4], target = 6
# Output: [1, 2]
print(two_sum([3, 2, 4], 6))




# brute force ... 
# time o(n^2)
# def two_sum_brute_force(nums: list[int], target: int) -> list[int]:
#     n = len(nums)
#     for i in range(n):
#         for j in range(i + 1, n):
#             if nums[i] + nums[j] == target:
#                 return [i, j]
#     return []