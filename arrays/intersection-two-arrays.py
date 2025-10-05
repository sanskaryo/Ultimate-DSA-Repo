"""
Intersection of Two Arrays
==========================

Problem: Given two integer arrays, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

Approach 1 - Hash Set (Optimized):
- Convert first array to a set for O(1) lookups
- Iterate through second array and check if each element exists in the set
- Add elements that exist in both arrays to result set
- Convert result set back to list

Approach 2 - Two Sets:
- Convert both arrays to sets
- Use set intersection operation to find common elements
- Convert result back to list

Approach 3 - Sorting + Two Pointers:
- Sort both arrays first
- Use two pointers to find common elements
- Skip duplicates while iterating

Approach 4 - Brute Force:
- For each element in first array, check if it exists in second array
- Use set to avoid duplicate results

Time Complexity: O(n + m) for hash set, O(n log n + m log m) for sorting
Space Complexity: O(min(n, m)) for hash set, O(1) for sorting (excluding result)
"""

from typing import List, Set


class IntersectionSolver:
    
    @staticmethod
    def intersection_optimized(nums1: List[int], nums2: List[int]) -> List[int]:
        """
        Find intersection using hash set approach.
        
        Args:
            nums1: First array of integers
            nums2: Second array of integers
            
        Returns:
            List containing unique elements present in both arrays
            
        Example:
            Input: nums1 = [1, 2, 2, 1], nums2 = [2, 2]
            Output: [2]
        """
        # Convert first array to set for O(1) lookups
        set1 = set(nums1)
        
        # Set to store intersection results (automatically handles uniqueness)
        intersection_set = set()
        
        # Check each element in second array
        for num in nums2:
            # If element exists in first array, add to result
            if num in set1:
                intersection_set.add(num)
        
        # Convert set back to list
        return list(intersection_set)
    
    @staticmethod
    def intersection_two_sets(nums1: List[int], nums2: List[int]) -> List[int]:
        """
        Find intersection using built-in set intersection.
        Most pythonic approach.
        """
        set1 = set(nums1)
        set2 = set(nums2)
        
        # Use set intersection operation
        return list(set1 & set2)
    
    @staticmethod
    def intersection_sorting(nums1: List[int], nums2: List[int]) -> List[int]:
        """
        Find intersection using sorting + two pointers approach.
        Time: O(n log n + m log m), Space: O(1) excluding result
        """
        # Sort both arrays
        sorted1 = sorted(nums1)
        sorted2 = sorted(nums2)
        
        # Two pointers and result set
        i, j = 0, 0
        intersection_set = set()
        
        # Use two pointers to find common elements
        while i < len(sorted1) and j < len(sorted2):
            if sorted1[i] == sorted2[j]:
                # Found common element
                intersection_set.add(sorted1[i])
                i += 1
                j += 1
            elif sorted1[i] < sorted2[j]:
                i += 1
            else:
                j += 1
        
        return list(intersection_set)
    
    @staticmethod
    def intersection_brute_force(nums1: List[int], nums2: List[int]) -> List[int]:
        """
        Find intersection using brute force approach.
        Time: O(n * m), Space: O(min(n, m))
        Helps understand the problem better.
        """
        intersection_set = set()
        
        # Check each element in first array
        for num1 in nums1:
            # Check if it exists in second array
            if num1 in nums2:
                intersection_set.add(num1)
        
        return list(intersection_set)
    
    @staticmethod
    def intersection_with_counts(nums1: List[int], nums2: List[int]) -> List[int]:
        """
        Bonus: Find intersection and also return how many times each element appears.
        Returns list of tuples (element, count_in_nums1, count_in_nums2).
        """
        from collections import Counter
        
        count1 = Counter(nums1)
        count2 = Counter(nums2)
        
        result = []
        common_elements = set(nums1) & set(nums2)
        
        for element in common_elements:
            result.append((element, count1[element], count2[element]))
        
        return result
    
    @staticmethod
    def run_test_cases():
        """Run comprehensive test cases for all approaches."""
        print("=== Intersection of Two Arrays Test Results ===\n")
        
        # Test cases with expected results (sorted for easy comparison)
        test_cases = [
            ([1, 2, 2, 1], [2, 2], [2]),                    # Basic intersection
            ([4, 9, 5], [9, 4, 9, 8, 4], [4, 9]),          # Multiple common elements
            ([1, 2, 3], [4, 5, 6], []),                     # No intersection
            ([1, 2, 3, 4, 5], [3, 4, 5, 6, 7], [3, 4, 5]), # Multiple intersections
            ([1], [1], [1]),                                 # Single element match
            ([1], [2], []),                                  # Single element no match
            ([], [1, 2, 3], []),                            # Empty first array
            ([1, 2, 3], [], []),                            # Empty second array
            ([], [], []),                                    # Both arrays empty
            ([1, 1, 1], [1, 1, 1], [1])                    # All same elements
        ]
        
        descriptions = [
            "Basic intersection with duplicates",
            "Multiple common elements",
            "No common elements",
            "Multiple intersections",
            "Single element arrays - match",
            "Single element arrays - no match",
            "Empty first array",
            "Empty second array",
            "Both arrays empty",
            "All elements same"
        ]
        
        for i, (nums1, nums2, expected) in enumerate(test_cases):
            print(f"Test Case {i + 1}: {descriptions[i]}")
            print(f"Input: nums1 = {nums1}, nums2 = {nums2}")
            print(f"Expected: {sorted(expected)}")
            
            # Test all approaches
            result_optimized = IntersectionSolver.intersection_optimized(nums1.copy(), nums2.copy())
            result_two_sets = IntersectionSolver.intersection_two_sets(nums1.copy(), nums2.copy())
            result_sorting = IntersectionSolver.intersection_sorting(nums1.copy(), nums2.copy())
            result_brute_force = IntersectionSolver.intersection_brute_force(nums1.copy(), nums2.copy())
            
            # Sort results for comparison (since order doesn't matter)
            result_optimized.sort()
            result_two_sets.sort()
            result_sorting.sort()
            result_brute_force.sort()
            
            print(f"Hash Set Result: {result_optimized}")
            print(f"Two Sets Result: {result_two_sets}")
            print(f"Sorting Result: {result_sorting}")
            print(f"Brute Force Result: {result_brute_force}")
            
            # Show counts if there's an intersection
            if expected:
                counts_result = IntersectionSolver.intersection_with_counts(nums1, nums2)
                print(f"With Counts: {counts_result}")
            
            # Verify correctness
            expected_sorted = sorted(expected)
            optimized_correct = result_optimized == expected_sorted
            two_sets_correct = result_two_sets == expected_sorted
            sorting_correct = result_sorting == expected_sorted
            brute_force_correct = result_brute_force == expected_sorted
            
            print(f"✅ Hash Set: {'PASSED' if optimized_correct else 'FAILED'}")
            print(f"✅ Two Sets: {'PASSED' if two_sets_correct else 'FAILED'}")
            print(f"✅ Sorting: {'PASSED' if sorting_correct else 'FAILED'}")
            print(f"✅ Brute Force: {'PASSED' if brute_force_correct else 'FAILED'}")
            print("-" * 70)


def main():
    """Main function to run all test cases."""
    IntersectionSolver.run_test_cases()
    
    # Interactive example
    print("\n=== Interactive Example ===")
    nums1 = [1, 2, 2, 1, 3, 4]
    nums2 = [2, 2, 3, 5, 6]
    print(f"Finding intersection of {nums1} and {nums2}")
    
    # Show step-by-step process for hash set approach
    print("\nStep-by-step process (Hash Set approach):")
    set1 = set(nums1)
    print(f"Step 1: Convert nums1 to set: {set1}")
    
    intersection_set = set()
    print(f"Step 2: Check each element in nums2:")
    
    for i, num in enumerate(nums2):
        print(f"  Check {num}: ", end="")
        if num in set1:
            intersection_set.add(num)
            print(f"✅ Found in nums1, added to result. Result so far: {intersection_set}")
        else:
            print(f"❌ Not in nums1, skipping.")
    
    result = list(intersection_set)
    print(f"\nFinal intersection: {result}")
    
    # Performance comparison
    print(f"\n=== Performance Analysis ===")
    print("For arrays of size n and m:")
    print("• Hash Set:     O(n + m) time, O(min(n,m)) space - Best general approach")
    print("• Two Sets:     O(n + m) time, O(n + m) space - Most pythonic")
    print("• Sorting:      O(n log n + m log m) time, O(1) space - Good for sorted data")
    print("• Brute Force:  O(n * m) time, O(min(n,m)) space - Only for small arrays")


if __name__ == "__main__":
    main()
