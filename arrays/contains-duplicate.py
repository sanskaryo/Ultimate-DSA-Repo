"""
Contains Duplicate
==================

Problem: Given an integer array, return true if any value appears at least twice 
in the array, and return false if every element is distinct.

Approach 1 - Hash Set (Optimized):
- Use hash set to store elements as we iterate
- For each element, check if it already exists in the set
- If found, return True (duplicate found)
- If not found, add element to set and continue
- If we finish iteration without finding duplicates, return False

Approach 2 - Sorting:
- Sort the array first
- Check adjacent elements for duplicates
- If any adjacent pair is equal, return True

Approach 3 - Brute Force:
- For each element, check all other elements for duplicates
- Nested loop approach

Time Complexity: O(n) for hash set, O(n log n) for sorting, O(n²) for brute force
Space Complexity: O(n) for hash set, O(1) for sorting, O(1) for brute force
"""

from typing import List, Set


class ContainsDuplicateSolver:
    
    @staticmethod
    def contains_duplicate_optimized(nums: List[int]) -> bool:
        """
        Check for duplicates using hash set approach.
        
        Args:
            nums: List of integers
            
        Returns:
            True if duplicates exist, False otherwise
            
        Example:
            Input: nums = [1, 2, 3, 1]
            Output: True (1 appears twice)
        """
        # Hash set to store seen elements
        seen_elements = set()
        
        # Check each element
        for num in nums:
            # If element already exists in set, we found a duplicate
            if num in seen_elements:
                return True
            # Add current element to set
            seen_elements.add(num)
        
        # No duplicates found
        return False
    
    @staticmethod
    def contains_duplicate_sorting(nums: List[int]) -> bool:
        """
        Check for duplicates using sorting approach.
        Time: O(n log n), Space: O(1)
        """
        if len(nums) <= 1:
            return False
        
        # Sort the array
        nums_sorted = sorted(nums)
        
        # Check adjacent elements
        for i in range(1, len(nums_sorted)):
            if nums_sorted[i] == nums_sorted[i - 1]:
                return True
        
        return False
    
    @staticmethod
    def contains_duplicate_brute_force(nums: List[int]) -> bool:
        """
        Check for duplicates using brute force approach.
        Time: O(n²), Space: O(1)
        Helps understand the problem better.
        """
        array_length = len(nums)
        
        # Check each pair of elements
        for i in range(array_length):
            for j in range(i + 1, array_length):
                if nums[i] == nums[j]:
                    return True
        
        return False
    
    @staticmethod
    def contains_duplicate_pythonic(nums: List[int]) -> bool:
        """
        Pythonic one-liner approach using set properties.
        If set length differs from list length, duplicates exist.
        """
        return len(set(nums)) != len(nums)
    
    @staticmethod
    def find_first_duplicate(nums: List[int]) -> int:
        """
        Bonus function: Find the first duplicate element.
        Returns the first element that appears twice, or -1 if no duplicates.
        """
        seen_elements = set()
        
        for num in nums:
            if num in seen_elements:
                return num
            seen_elements.add(num)
        
        return -1
    
    @staticmethod
    def run_test_cases():
        """Run comprehensive test cases for all approaches."""
        print("=== Contains Duplicate Test Results ===\n")
        
        # Test cases with expected results
        test_cases = [
            ([1, 2, 3, 1], True),                    # Basic duplicate case
            ([1, 2, 3, 4], False),                   # No duplicates
            ([1, 1, 1, 3, 3, 4, 3, 2, 4, 2], True), # Multiple duplicates
            ([1], False),                            # Single element
            ([], False),                             # Empty array
            ([0, 0], True),                          # Two identical elements
            ([-1, -2, -3, -1], True),               # Negative numbers with duplicate
            ([1000000, 999999, 1000000], True),     # Large numbers
            ([1, 2, 3, 4, 5, 6, 7, 8, 9], False)   # Longer array without duplicates
        ]
        
        descriptions = [
            "Basic case with duplicate at different positions",
            "No duplicates present",
            "Multiple different duplicates",
            "Single element array",
            "Empty array edge case",
            "Two identical elements",
            "Negative numbers with duplicates",
            "Large numbers case",
            "Longer array without duplicates"
        ]
        
        for i, (nums, expected) in enumerate(test_cases):
            print(f"Test Case {i + 1}: {descriptions[i]}")
            print(f"Input: {nums}")
            print(f"Expected: {expected}")
            
            # Test all approaches
            result_optimized = ContainsDuplicateSolver.contains_duplicate_optimized(nums.copy())
            result_sorting = ContainsDuplicateSolver.contains_duplicate_sorting(nums.copy())
            result_brute_force = ContainsDuplicateSolver.contains_duplicate_brute_force(nums.copy())
            result_pythonic = ContainsDuplicateSolver.contains_duplicate_pythonic(nums.copy())
            
            print(f"Hash Set Result: {result_optimized}")
            print(f"Sorting Result: {result_sorting}")
            print(f"Brute Force Result: {result_brute_force}")
            print(f"Pythonic Result: {result_pythonic}")
            
            # Find first duplicate if it exists
            if expected:
                first_duplicate = ContainsDuplicateSolver.find_first_duplicate(nums)
                print(f"First Duplicate Found: {first_duplicate}")
            
            # Verify correctness
            optimized_correct = result_optimized == expected
            sorting_correct = result_sorting == expected
            brute_force_correct = result_brute_force == expected
            pythonic_correct = result_pythonic == expected
            
            print(f"✅ Hash Set: {'PASSED' if optimized_correct else 'FAILED'}")
            print(f"✅ Sorting: {'PASSED' if sorting_correct else 'FAILED'}")
            print(f"✅ Brute Force: {'PASSED' if brute_force_correct else 'FAILED'}")
            print(f"✅ Pythonic: {'PASSED' if pythonic_correct else 'FAILED'}")
            print("-" * 70)


def main():
    """Main function to run all test cases."""
    ContainsDuplicateSolver.run_test_cases()
    
    # Interactive example
    print("\n=== Interactive Example ===")
    sample_nums = [1, 3, 2, 4, 3, 5]
    print(f"Checking array: {sample_nums}")
    
    # Show step-by-step process for hash set approach
    print("\nStep-by-step process (Hash Set approach):")
    seen = set()
    
    for i, num in enumerate(sample_nums):
        print(f"Step {i + 1}: Checking element {num}")
        if num in seen:
            print(f"  ❌ Element {num} already seen! Duplicate found.")
            print(f"  Seen elements so far: {seen}")
            break
        else:
            seen.add(num)
            print(f"  ✅ Element {num} is new. Adding to seen set.")
            print(f"  Seen elements so far: {seen}")
    else:
        print("  ✅ No duplicates found in the entire array.")
    
    # Performance comparison
    print(f"\n=== Performance Analysis ===")
    print("For an array of size n:")
    print("• Hash Set:    O(n) time, O(n) space - Best for most cases")
    print("• Sorting:     O(n log n) time, O(1) space - Good when space is limited")
    print("• Brute Force: O(n²) time, O(1) space - Only for very small arrays")
    print("• Pythonic:    O(n) time, O(n) space - Clean but less educational")


if __name__ == "__main__":
    main()
