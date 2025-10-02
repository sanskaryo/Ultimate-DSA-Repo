"""
Remove Duplicates from Sorted Array
===================================

Problem: Given a sorted array, remove duplicates in-place and return the new length.
The relative order of elements should be kept the same.

Approach 1 - Two Pointers (Optimized):
- Use slow pointer to track position for next unique element
- Use fast pointer to scan through array
- When fast pointer finds new unique element, place it at slow pointer position
- Increment slow pointer only when we place a new unique element

Approach 2 - Brute Force:
- Use additional space to track unique elements
- Not optimal for in-place requirement but helps understand the problem

Time Complexity: O(n) for two pointers, O(n) for brute force
Space Complexity: O(1) for two pointers, O(n) for brute force
"""

from typing import List


class RemoveDuplicatesSolver:
    
    @staticmethod
    def remove_duplicates_optimized(nums: List[int]) -> int:
        """
        Remove duplicates from sorted array using two-pointer approach.
        
        Args:
            nums: Sorted list of integers (modified in-place)
            
        Returns:
            Length of array after removing duplicates
            
        Example:
            Input: nums = [1, 1, 2]
            Output: 2, and nums = [1, 2, _]
            Explanation: First 2 elements are unique
        """
        # Handle edge case - empty array
        if not nums:
            return 0
        
        # Slow pointer - tracks position for next unique element
        slow_pointer = 0
        
        # Fast pointer - scans through array starting from index 1
        for fast_pointer in range(1, len(nums)):
            # If current element is different from previous unique element
            if nums[fast_pointer] != nums[slow_pointer]:
                # Move slow pointer to next position
                slow_pointer += 1
                # Place the new unique element at slow pointer position
                nums[slow_pointer] = nums[fast_pointer]
        
        # Return length of unique elements (slow_pointer + 1)
        return slow_pointer + 1
    
    @staticmethod
    def remove_duplicates_brute_force(nums: List[int]) -> int:
        """
        Remove duplicates using additional space for comparison.
        Time: O(n), Space: O(n)
        Not optimal for in-place requirement but helps understand problem.
        """
        if not nums:
            return 0
        
        # Track unique elements
        unique_elements = []
        
        # Add first element (always unique in sorted array)
        unique_elements.append(nums[0])
        
        # Check each element against the last unique element
        for i in range(1, len(nums)):
            if nums[i] != unique_elements[-1]:
                unique_elements.append(nums[i])
        
        # Copy unique elements back to original array
        for i in range(len(unique_elements)):
            nums[i] = unique_elements[i]
        
        return len(unique_elements)
    
    @staticmethod
    def print_array_with_length(nums: List[int], length: int):
        """Print array showing only the valid elements up to given length."""
        result = nums[:length] + ['_'] * (len(nums) - length)
        print(f"[{', '.join(map(str, result))}]")
    
    @staticmethod
    def run_test_cases():
        """Run comprehensive test cases for both approaches."""
        print("=== Remove Duplicates from Sorted Array Test Results ===\n")
        
        # Test cases with expected results
        test_cases = [
            ([1, 1, 2], 2, [1, 2]),                           # Basic case with duplicates
            ([0, 0, 1, 1, 1, 2, 2, 3, 3, 4], 5, [0, 1, 2, 3, 4]),  # Multiple duplicates
            ([1, 2, 3, 4, 5], 5, [1, 2, 3, 4, 5]),           # No duplicates
            ([1], 1, [1]),                                     # Single element
            ([2, 2, 2, 2], 1, [2]),                          # All same elements
            ([], 0, [])                                        # Empty array
        ]
        
        descriptions = [
            "Basic case with some duplicates",
            "Multiple consecutive duplicates",
            "No duplicates present",
            "Single element array",
            "All elements are same",
            "Empty array edge case"
        ]
        
        for i, (original_nums, expected_length, expected_unique) in enumerate(test_cases):
            print(f"Test Case {i + 1}: {descriptions[i]}")
            print(f"Input: {original_nums}")
            print(f"Expected Length: {expected_length}")
            print(f"Expected Unique Elements: {expected_unique}")
            
            # Test optimized approach
            nums_optimized = original_nums.copy()
            result_length_optimized = RemoveDuplicatesSolver.remove_duplicates_optimized(nums_optimized)
            
            print(f"Optimized Result Length: {result_length_optimized}")
            print("Optimized Result Array: ", end="")
            RemoveDuplicatesSolver.print_array_with_length(nums_optimized, result_length_optimized)
            
            # Test brute force approach
            nums_brute_force = original_nums.copy()
            result_length_brute_force = RemoveDuplicatesSolver.remove_duplicates_brute_force(nums_brute_force)
            
            print(f"Brute Force Result Length: {result_length_brute_force}")
            print("Brute Force Result Array: ", end="")
            RemoveDuplicatesSolver.print_array_with_length(nums_brute_force, result_length_brute_force)
            
            # Verify correctness
            optimized_correct = (result_length_optimized == expected_length and 
                               nums_optimized[:result_length_optimized] == expected_unique)
            brute_force_correct = (result_length_brute_force == expected_length and 
                                 nums_brute_force[:result_length_brute_force] == expected_unique)
            
            print(f"✅ Optimized: {'PASSED' if optimized_correct else 'FAILED'}")
            print(f"✅ Brute Force: {'PASSED' if brute_force_correct else 'FAILED'}")
            print("-" * 70)


def main():
    """Main function to run all test cases."""
    RemoveDuplicatesSolver.run_test_cases()
    
    # Interactive example
    print("\n=== Interactive Example ===")
    sample_nums = [1, 1, 2, 2, 3, 4, 4, 5]
    print(f"Original array: {sample_nums}")
    
    # Show step-by-step process
    print("\nStep-by-step process:")
    nums_copy = sample_nums.copy()
    slow = 0
    print(f"Initial: slow=0, array={nums_copy}")
    
    for fast in range(1, len(nums_copy)):
        if nums_copy[fast] != nums_copy[slow]:
            slow += 1
            nums_copy[slow] = nums_copy[fast]
            print(f"Found unique {nums_copy[fast]}: slow={slow}, array={nums_copy}")
    
    new_length = slow + 1
    print("\nFinal result:")
    print(f"New length: {new_length}")
    print("Array after removing duplicates: ", end="")
    RemoveDuplicatesSolver.print_array_with_length(nums_copy, new_length)


if __name__ == "__main__":
    main()
