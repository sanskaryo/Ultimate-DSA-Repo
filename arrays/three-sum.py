from typing import List

def three_sum_brute_force(nums: List[int], target: int) -> List[int]:
    """
    Brute Force Approach (O(n^3))
    
    Simply check all possible triplets.
    
    Time Complexity: O(n^3)
    Space Complexity: O(1)
    """
    n = len(nums)
    
    # Need at least 3 elements for a triplet
    if n < 3:
        # return an empty array
        return []

    # Try all possible combinations of three different indices
    for i in range(n):
        for j in range(i + 1, n):            # j starts after i to avoid duplicates
            for k in range(j + 1, n):        # k starts after j to avoid duplicates
                # Check if current triplet sums to target
                if nums[i] + nums[j] + nums[k] == target:
                    return [i, j, k]         # Return indices of the triplet
    
    return []  # No triplet found


def three_sum(nums: List[int], target: int) -> List[int]:
    """
    Optimal Hash Map Approach (O(n^2))
    
    For each element, reduce the problem to a Two Sum (target - nums[i]).
    Use a dictionary to store complements.
    
    Time Complexity: O(n^2)
    Space Complexity: O(n)
    """
    n = len(nums)
    
    # Need at least 3 elements for a triplet
    if n < 3:
        # return an empty array
        return []

    # Fix the first element and solve Two Sum for the remaining elements
    for i in range(n):
        seen = {}  # Maps value to its index
        new_target = target - nums[i]  # What the other two numbers should sum to
        
        # Look for two numbers that sum to new_target in the remaining array
        for j in range(i + 1, n):
            complement = new_target - nums[j]  # What we need to complete the triplet
            
            # Check if we've seen the complement before
            if complement in seen:
                # Found triplet: nums[i] + nums[seen[complement]] + nums[j] = target
                return [i, seen[complement], j]
            
            # Store current number and its index for future lookups
            seen[nums[j]] = j
    
    return []  # No triplet found


# --- Test Cases ---
if __name__ == "__main__":
    # Test Case 1: Basic positive numbers with valid triplet
    # Expected: indices where nums[i] + nums[j] + nums[k] = 20
    # Array: [2, 7, 11, 15, -2], Target: 20
    # Solution: 2 + 7 + 11 = 20 (indices 0, 1, 2)
    nums1 = [2, 7, 11, 15, -2]
    target1 = 20
    result1 = three_sum(nums1, target1)
    if result1:
        print(f"Test 1 - Optimal: {result1}")
        print(f"Values: {nums1[result1[0]]} + {nums1[result1[1]]} + {nums1[result1[2]]} = {target1}")
    
    brute1 = three_sum_brute_force(nums1, target1)
    if brute1:
        print(f"Test 1 - Brute: {brute1}")
    
    # Test Case 2: Another set with valid triplet
    # Expected: indices where nums[i] + nums[j] + nums[k] = 22
    # Array: [1, 4, 6, 8, 10, 45], Target: 22
    # Solution: 4 + 8 + 10 = 22 (indices 1, 3, 4)
    nums2 = [1, 4, 6, 8, 10, 45]
    target2 = 22
    result2 = three_sum(nums2, target2)
    if result2:
        print(f"Test 2 - Optimal: {result2}")
        print(f"Values: {nums2[result2[0]]} + {nums2[result2[1]]} + {nums2[result2[2]]} = {target2}")
    
    # Test Case 3: No solution exists
    # Array: [1, 2, 3], Target: 100 (impossible to achieve)
    nums3 = [1, 2, 3]
    target3 = 100
    result3 = three_sum(nums3, target3)
    if not result3:
        print(f"Test 3 - No triplet found for target {target3}")