"""
Move Zeroes
===========

Problem: Given an integer array, move all 0's to the end while maintaining 
the relative order of non-zero elements. Must do this in-place.

Approach 1 - Two Pointers (Optimized):
- Use slow pointer to track position for next non-zero element
- Use fast pointer to scan through array
- When fast pointer finds non-zero element, place it at slow pointer position
- After placing all non-zeros, fill remaining positions with zeros

Approach 2 - Brute Force:
- Use additional array to store non-zero elements
- Copy non-zeros first, then fill remaining with zeros
- Copy back to original array

Time Complexity: O(n) for both approaches
Space Complexity: O(1) for two pointers, O(n) for brute force
"""

from typing import List


class MoveZeroesSolver:
    
    @staticmethod
    def move_zeroes_optimized(nums: List[int]) -> None:
        """
        Move all zeroes to end using two-pointer approach (in-place).
        
        Args:
            nums: List of integers (modified in-place)
            
        Example:
            Input: nums = [0, 1, 0, 3, 12]
            Output: nums = [1, 3, 12, 0, 0]
            Explanation: Non-zeros maintain relative order, zeros moved to end
        """
        # Handle edge case - empty array or single element
        if len(nums) <= 1:
            return
        
        # Slow pointer - tracks position for next non-zero element
        slow_pointer = 0
        
        # Fast pointer - scans through array to find non-zero elements
        for fast_pointer in range(len(nums)):
            # If current element is non-zero
            if nums[fast_pointer] != 0:
                # Place non-zero element at slow pointer position
                nums[slow_pointer] = nums[fast_pointer]
                # Move slow pointer to next position
                slow_pointer += 1
        
        # Fill remaining positions with zeros
        for i in range(slow_pointer, len(nums)):
            nums[i] = 0
    
    @staticmethod
    def move_zeroes_swap_optimized(nums: List[int]) -> None:
        """
        Alternative optimized approach using swapping.
        Maintains relative order and minimizes writes.
        """
        if len(nums) <= 1:
            return
        
        # Position for next non-zero element
        non_zero_pos = 0
        
        # Move all non-zero elements to front
        for i in range(len(nums)):
            if nums[i] != 0:
                # Swap only if positions are different
                if i != non_zero_pos:
                    nums[non_zero_pos], nums[i] = nums[i], nums[non_zero_pos]
                non_zero_pos += 1
    
    @staticmethod
    def move_zeroes_brute_force(nums: List[int]) -> None:
        """
        Move zeroes using additional space for comparison.
        Time: O(n), Space: O(n)
        Helps understand the problem better.
        """
        if len(nums) <= 1:
            return
        
        # Store non-zero elements
        non_zero_elements = []
        zero_count = 0
        
        # Separate non-zeros and count zeros
        for num in nums:
            if num != 0:
                non_zero_elements.append(num)
            else:
                zero_count += 1
        
        # Fill array: non-zeros first, then zeros
        for i in range(len(non_zero_elements)):
            nums[i] = non_zero_elements[i]
        
        for i in range(len(non_zero_elements), len(nums)):
            nums[i] = 0
    
    @staticmethod
    def print_array_changes(original: List[int], result: List[int], method: str):
        """Print before and after arrays to show the transformation."""
        print(f"{method}:")
        print(f"  Before: {original}")
        print(f"  After:  {result}")
    
    @staticmethod
    def verify_result(nums: List[int], expected: List[int]) -> bool:
        """Verify if the result matches expected output."""
        return nums == expected
    
    @staticmethod
    def run_test_cases():
        """Run comprehensive test cases for all approaches."""
        print("=== Move Zeroes Test Results ===\n")
        
        # Test cases with expected results
        test_cases = [
            ([0, 1, 0, 3, 12], [1, 3, 12, 0, 0]),      # Mixed zeros and non-zeros
            ([0, 0, 1], [1, 0, 0]),                     # Leading zeros
            ([1, 0, 0], [1, 0, 0]),                     # Trailing zeros
            ([0, 0, 0], [0, 0, 0]),                     # All zeros
            ([1, 2, 3], [1, 2, 3]),                     # No zeros
            ([0], [0]),                                  # Single zero
            ([5], [5]),                                  # Single non-zero
            ([0, 1], [1, 0]),                           # Two elements
            ([1, 0], [1, 0])                            # Two elements (already correct)
        ]
        
        descriptions = [
            "Mixed zeros and non-zeros",
            "Leading zeros case",
            "Trailing zeros case", 
            "All zeros case",
            "No zeros present",
            "Single zero element",
            "Single non-zero element",
            "Two elements - zero first",
            "Two elements - zero last"
        ]
        
        for i, (original_nums, expected) in enumerate(test_cases):
            print(f"Test Case {i + 1}: {descriptions[i]}")
            print(f"Input: {original_nums}")
            print(f"Expected: {expected}")
            
            # Test optimized approach
            nums_optimized = original_nums.copy()
            MoveZeroesSolver.move_zeroes_optimized(nums_optimized)
            MoveZeroesSolver.print_array_changes(original_nums, nums_optimized, "Optimized (Two Pointers)")
            
            # Test swap approach
            nums_swap = original_nums.copy()
            MoveZeroesSolver.move_zeroes_swap_optimized(nums_swap)
            MoveZeroesSolver.print_array_changes(original_nums, nums_swap, "Optimized (Swapping)")
            
            # Test brute force approach
            nums_brute_force = original_nums.copy()
            MoveZeroesSolver.move_zeroes_brute_force(nums_brute_force)
            MoveZeroesSolver.print_array_changes(original_nums, nums_brute_force, "Brute Force")
            
            # Verify correctness
            optimized_correct = MoveZeroesSolver.verify_result(nums_optimized, expected)
            swap_correct = MoveZeroesSolver.verify_result(nums_swap, expected)
            brute_force_correct = MoveZeroesSolver.verify_result(nums_brute_force, expected)
            
            print(f"✅ Two Pointers: {'PASSED' if optimized_correct else 'FAILED'}")
            print(f"✅ Swapping: {'PASSED' if swap_correct else 'FAILED'}")
            print(f"✅ Brute Force: {'PASSED' if brute_force_correct else 'FAILED'}")
            print("-" * 70)


def main():
    """Main function to run all test cases."""
    MoveZeroesSolver.run_test_cases()
    
    # Interactive example
    print("\n=== Interactive Example ===")
    sample_nums = [0, 1, 0, 3, 12, 0, 5]
    print(f"Original array: {sample_nums}")
    
    # Show step-by-step process for two-pointer approach
    print("\nStep-by-step process (Two Pointers):")
    nums_copy = sample_nums.copy()
    slow = 0
    print(f"Initial: slow=0, array={nums_copy}")
    
    # Phase 1: Move non-zeros to front
    for fast in range(len(nums_copy)):
        if nums_copy[fast] != 0:
            nums_copy[slow] = nums_copy[fast]
            slow += 1
            print(f"Found non-zero {nums_copy[fast]}: slow={slow}, array={nums_copy}")
    
    # Phase 2: Fill remaining with zeros
    original_slow = slow
    for i in range(slow, len(nums_copy)):
        nums_copy[i] = 0
    
    print(f"\nAfter filling remaining {len(nums_copy) - original_slow} positions with zeros:")
    print(f"Final result: {nums_copy}")


if __name__ == "__main__":
    main()
