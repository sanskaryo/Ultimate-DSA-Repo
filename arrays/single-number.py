"""
Single Number
=============

Problem: Given a non-empty array of integers nums, every element appears twice 
except for one. Find that single one. You must implement a solution with a 
linear runtime complexity and use only constant extra space.

Approach 1 - XOR Bit Manipulation (Optimized):
- Use XOR operation: a ^ a = 0 and a ^ 0 = a
- XOR all elements together
- Duplicate numbers cancel out (become 0)
- Single number remains

Approach 2 - Hash Set:
- Use set to track seen numbers
- Add number if not seen, remove if already seen
- Remaining number is the single one
- Uses O(n) space

Approach 3 - Math Approach:
- 2 * (sum of unique numbers) - (sum of all numbers) = single number
- Uses O(n) space for set

Time Complexity: O(n) for all approaches
Space Complexity: O(1) for XOR, O(n) for hash set and math
"""

from typing import List


class SingleNumberSolver:
    
    @staticmethod
    def single_number_optimized(nums: List[int]) -> int:
        """
        Find single number using XOR bit manipulation.
        
        Args:
            nums: List of integers where every element appears twice except one
            
        Returns:
            The single number that appears only once
            
        Example:
            Input: nums = [2, 2, 1]
            Output: 1
            
            Input: nums = [4, 1, 2, 1, 2]
            Output: 4
            
        Explanation:
            XOR properties:
            - a ^ a = 0 (same numbers cancel out)
            - a ^ 0 = a (XOR with 0 gives the number itself)
            - XOR is commutative and associative
        """
        result = 0
        
        for num in nums:
            result ^= num
        
        return result
    
    @staticmethod
    def single_number_hash_set(nums: List[int]) -> int:
        """
        Find single number using hash set.
        Add if not present, remove if already present.
        """
        seen = set()
        
        for num in nums:
            if num in seen:
                seen.remove(num)
            else:
                seen.add(num)
        
        return seen.pop()
    
    @staticmethod
    def single_number_math(nums: List[int]) -> int:
        """
        Find single number using mathematical approach.
        2 * (sum of unique) - (sum of all) = single number
        """
        return 2 * sum(set(nums)) - sum(nums)
    
    @staticmethod
    def single_number_brute_force(nums: List[int]) -> int:
        """
        Brute force: check each number's count.
        For educational purposes only.
        Time: O(n²), Space: O(1)
        """
        for i in range(len(nums)):
            count = 0
            for j in range(len(nums)):
                if nums[i] == nums[j]:
                    count += 1
            if count == 1:
                return nums[i]
        return -1
    
    @staticmethod
    def run_test_cases():
        """Run comprehensive test cases for all approaches."""
        print("=== Single Number Test Results ===\n")
        
        test_cases = [
            ([2, 2, 1], 1),
            ([4, 1, 2, 1, 2], 4),
            ([1], 1),
            ([1, 3, 1, -1, 3], -1),
            ([0, 1, 0], 1),
            ([7, 3, 5, 3, 5], 7),
            ([-1, -1, -2], -2),
            ([100, 200, 100], 200),
            ([5, 5, 9, 9, 2, 2, 1], 1)
        ]
        
        descriptions = [
            "Basic case with three elements",
            "Multiple pairs with single number",
            "Single element array",
            "Negative number as single",
            "Zero in array",
            "Larger numbers",
            "All negative numbers",
            "Large value differences",
            "Multiple pairs case"
        ]
        
        for i, (nums, expected) in enumerate(test_cases):
            print(f"Test Case {i + 1}: {descriptions[i]}")
            print(f"Input:    {nums}")
            print(f"Expected: {expected}")
            
            result_xor = SingleNumberSolver.single_number_optimized(nums.copy())
            result_set = SingleNumberSolver.single_number_hash_set(nums.copy())
            result_math = SingleNumberSolver.single_number_math(nums.copy())
            
            print(f"XOR Result:      {result_xor}")
            print(f"Hash Set Result: {result_set}")
            print(f"Math Result:     {result_math}")
            
            xor_correct = result_xor == expected
            set_correct = result_set == expected
            math_correct = result_math == expected
            
            print(f"✅ XOR:      {'PASSED' if xor_correct else 'FAILED'}")
            print(f"✅ Hash Set: {'PASSED' if set_correct else 'FAILED'}")
            print(f"✅ Math:     {'PASSED' if math_correct else 'FAILED'}")
            print("-" * 70)


def main():
    """Main function to run all test cases."""
    SingleNumberSolver.run_test_cases()
    
    print("\n=== Interactive Example ===")
    sample_nums = [4, 1, 2, 1, 2]
    print(f"Finding single number in: {sample_nums}")
    
    print("\nStep-by-step XOR process:")
    result = 0
    
    for i, num in enumerate(sample_nums):
        prev_result = result
        result ^= num
        print(f"Step {i + 1}: {prev_result} ^ {num} = {result} (binary: {bin(result)})")
    
    print(f"\nFinal single number: {result}")
    
    print("\n=== XOR Properties Explanation ===")
    print("Why XOR works:")
    print("1. a ^ a = 0  (same numbers cancel out)")
    print("2. a ^ 0 = a  (XOR with 0 gives the number)")
    print("3. XOR is commutative: a ^ b = b ^ a")
    print("4. XOR is associative: (a ^ b) ^ c = a ^ (b ^ c)")
    
    print("\nExample: [4, 1, 2, 1, 2]")
    print("4 ^ 1 ^ 2 ^ 1 ^ 2")
    print("= 4 ^ (1 ^ 1) ^ (2 ^ 2)")
    print("= 4 ^ 0 ^ 0")
    print("= 4")
    
    print("\n=== Performance Analysis ===")
    print("For an array of n elements:")
    print("• XOR Approach:      O(n) time, O(1) space - Optimal solution")
    print("• Hash Set Approach: O(n) time, O(n) space - Alternative")
    print("• Math Approach:     O(n) time, O(n) space - Mathematical")
    print("• Brute Force:       O(n²) time, O(1) space - Not recommended")
    
    print("\n=== Binary XOR Table ===")
    print("XOR truth table:")
    print("0 ^ 0 = 0")
    print("0 ^ 1 = 1")
    print("1 ^ 0 = 1")
    print("1 ^ 1 = 0")


if __name__ == "__main__":
    main()
