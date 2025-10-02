"""
Two Sum Problem
===============

Problem: Given an array of integers and a target sum, return indices of two numbers 
that add up to the target. Assume exactly one solution exists.

Approach 1 - Hash Map (Optimized):
- Use hash map to store numbers and their indices as we iterate
- For each number, check if (target - current_number) exists in hash map
- If found, return both indices
- If not found, add current number and index to hash map

Approach 2 - Brute Force:
- Try all possible pairs using nested loops
- Check if each pair sums to target

Time Complexity: O(n) for hash map, O(n²) for brute force
Space Complexity: O(n) for hash map, O(1) for brute force
"""

from typing import List, Tuple


class TwoSumSolver:
    
    @staticmethod
    def two_sum_optimized(nums: List[int], target: int) -> List[int]:
        """
        Find two numbers that add up to target using hash map approach.
        
        Args:
            nums: List of integers
            target: Target sum we want to achieve
            
        Returns:
            List containing indices of the two numbers that sum to target
            
        Example:
            Input: nums = [2, 7, 11, 15], target = 9
            Output: [0, 1] (because nums[0] + nums[1] = 2 + 7 = 9)
        """
        # Hash map to store number -> index mapping
        num_to_index = {}
        
        # Iterate through the array with both index and value
        for current_index, current_num in enumerate(nums):
            # Calculate what number we need to reach the target
            needed_num = target - current_num
            
            # Check if the needed number exists in our hash map
            if needed_num in num_to_index:
                # Found the pair! Return indices
                return [num_to_index[needed_num], current_index]
            
            # Store current number and its index for future lookups
            num_to_index[current_num] = current_index
        
        # This should never happen if problem guarantees a solution exists
        return []
    
    @staticmethod
    def two_sum_brute_force(nums: List[int], target: int) -> List[int]:
        """
        Find two numbers that add up to target using brute force approach.
        Time: O(n²), Space: O(1)
        Useful for understanding the problem better.
        """
        array_length = len(nums)
        
        # Try all possible pairs
        for first_index in range(array_length - 1):
            for second_index in range(first_index + 1, array_length):
                # Check if current pair sums to target
                if nums[first_index] + nums[second_index] == target:
                    return [first_index, second_index]
        
        # No solution found
        return []
    
    @staticmethod
    def run_test_cases():
        """Run comprehensive test cases for both approaches."""
        print("=== Two Sum Problem Test Results ===\n")
        
        # Test cases with expected results
        test_cases = [
            ([2, 7, 11, 15], 9, [0, 1]),           # Basic case
            ([3, 2, 4], 6, [1, 2]),                # Target in middle
            ([3, 3], 6, [0, 1]),                   # Duplicate numbers
            ([1, 5, 3, 8, 2], 10, [1, 3]),         # Multiple possibilities
            ([-1, -2, -3, -4, -5], -8, [2, 4])     # Negative numbers
        ]
        
        descriptions = [
            "Basic case - first two elements sum to target",
            "Target requires elements from middle and end",
            "Duplicate numbers that sum to target",
            "Array with multiple valid pairs",
            "Negative numbers case"
        ]
        
        for i, (nums, target, expected) in enumerate(test_cases):
            print(f"Test Case {i + 1}: {descriptions[i]}")
            print(f"Input: nums = {nums}, target = {target}")
            print(f"Expected: {expected}")
            
            # Test optimized approach
            result_optimized = TwoSumSolver.two_sum_optimized(nums.copy(), target)
            print(f"Optimized Result: {result_optimized}")
            
            # Test brute force approach
            result_brute_force = TwoSumSolver.two_sum_brute_force(nums.copy(), target)
            print(f"Brute Force Result: {result_brute_force}")
            
            # Verify correctness (check if the indices give correct sum)
            def verify_result(result: List[int]) -> bool:
                if len(result) != 2:
                    return False
                return nums[result[0]] + nums[result[1]] == target
            
            optimized_correct = verify_result(result_optimized)
            brute_force_correct = verify_result(result_brute_force)
            
            print(f"✅ Optimized: {'PASSED' if optimized_correct else 'FAILED'}")
            print(f"✅ Brute Force: {'PASSED' if brute_force_correct else 'FAILED'}")
            print("-" * 60)


def main():
    """Main function to run all test cases."""
    TwoSumSolver.run_test_cases()
    
    # Interactive example
    print("\n=== Interactive Example ===")
    sample_nums = [2, 7, 11, 15]
    sample_target = 9
    
    print(f"Finding two numbers in {sample_nums} that sum to {sample_target}")
    result = TwoSumSolver.two_sum_optimized(sample_nums, sample_target)
    
    if result:
        print(f"Found at indices: {result}")
        print(f"Numbers: {sample_nums[result[0]]} + {sample_nums[result[1]]} = {sample_target}")
    else:
        print("No solution found!")


if __name__ == "__main__":
    main()
