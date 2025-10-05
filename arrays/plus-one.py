"""
Plus One
========

Problem: Given a large integer represented as an integer array digits, where each 
digits[i] is the ith digit of the integer. The digits are ordered from most 
significant to least significant in left-to-right order. Increment the large 
integer by one and return the resulting array of digits.

Approach 1 - Reverse Iteration with Carry (Optimized):
- Start from the last digit (least significant)
- Add 1 to the last digit
- Handle carry propagation: if digit becomes 10, set it to 0 and carry 1
- Continue until no carry or we've processed all digits
- If carry remains after processing all digits, insert 1 at the beginning

Approach 2 - Convert to Integer (Simple but Limited):
- Convert array to integer
- Add 1
- Convert back to array
- Limited by integer size constraints

Approach 3 - Edge Case Optimization:
- Check if last digit is not 9, simply increment and return
- Otherwise, handle carry propagation

Time Complexity: O(n) where n is the number of digits
Space Complexity: O(1) for in-place, O(n) if creating new array
"""

from typing import List


class PlusOneSolver:
    
    @staticmethod
    def plus_one_optimized(digits: List[int]) -> List[int]:
        """
        Add one to the number represented by digits array using carry propagation.
        
        Args:
            digits: List of integers representing a large number
            
        Returns:
            List of integers representing the incremented number
            
        Example:
            Input: digits = [1, 2, 3]
            Output: [1, 2, 4]
            
            Input: digits = [9, 9, 9]
            Output: [1, 0, 0, 0]
        """
        n = len(digits)
        
        # Traverse from right to left (least significant to most significant)
        for i in range(n - 1, -1, -1):
            # If current digit is less than 9, simply increment and return
            if digits[i] < 9:
                digits[i] += 1
                return digits
            
            # Current digit is 9, set it to 0 and continue (carry over)
            digits[i] = 0
        
        # If we're here, all digits were 9 (e.g., [9,9,9] -> [1,0,0,0])
        # Insert 1 at the beginning
        return [1] + digits
    
    @staticmethod
    def plus_one_with_carry(digits: List[int]) -> List[int]:
        """
        Add one using explicit carry variable.
        More verbose but easier to understand.
        """
        carry = 1  # We're adding 1 to the number
        result = digits.copy()
        
        # Process digits from right to left
        for i in range(len(result) - 1, -1, -1):
            # Add carry to current digit
            total = result[i] + carry
            result[i] = total % 10  # Get the digit (0-9)
            carry = total // 10     # Get the carry (0 or 1)
            
            # If no carry, we're done
            if carry == 0:
                break
        
        # If carry still exists, prepend it
        if carry > 0:
            result.insert(0, carry)
        
        return result
    
    @staticmethod
    def plus_one_convert(digits: List[int]) -> List[int]:
        """
        Convert to integer, add one, convert back.
        Simple but limited by integer size.
        Not recommended for very large numbers.
        """
        # Convert array to integer
        number = int(''.join(map(str, digits)))
        
        # Add one
        number += 1
        
        # Convert back to array
        return [int(d) for d in str(number)]
    
    @staticmethod
    def plus_one_recursive(digits: List[int], index: int = None) -> List[int]:
        """
        Recursive approach for educational purposes.
        Shows how carry propagation works recursively.
        """
        if index is None:
            index = len(digits) - 1
        
        # Base case: reached before the first digit with carry
        if index < 0:
            return [1] + digits
        
        # If current digit is less than 9, increment and return
        if digits[index] < 9:
            digits[index] += 1
            return digits
        
        # Set current digit to 0 and recurse to previous digit
        digits[index] = 0
        return PlusOneSolver.plus_one_recursive(digits, index - 1)
    
    @staticmethod
    def run_test_cases():
        """Run comprehensive test cases for all approaches."""
        print("=== Plus One Test Results ===\n")
        
        # Test cases with expected results
        test_cases = [
            ([1, 2, 3], [1, 2, 4]),                    # Basic case
            ([4, 3, 2, 1], [4, 3, 2, 2]),             # No carry needed
            ([9], [1, 0]),                             # Single digit 9
            ([9, 9, 9], [1, 0, 0, 0]),                # All 9s - carry propagation
            ([1, 9, 9], [2, 0, 0]),                   # Partial 9s
            ([0], [1]),                                # Edge case: zero
            ([8, 9, 9, 9], [9, 0, 0, 0]),             # Multiple 9s at end
            ([1, 2, 9], [1, 3, 0]),                   # Single 9 at end
            ([9, 8, 7, 6, 5, 4, 3, 2, 1, 0], 
             [9, 8, 7, 6, 5, 4, 3, 2, 1, 1])          # Long number
        ]
        
        descriptions = [
            "Basic increment without carry",
            "Increment without carry propagation",
            "Single digit 9 (edge case)",
            "All digits are 9 (maximum carry)",
            "Partial 9s requiring carry",
            "Edge case: incrementing zero",
            "Multiple 9s at the end",
            "Single 9 at the end",
            "Long number without carry at start"
        ]
        
        for i, (digits, expected) in enumerate(test_cases):
            print(f"Test Case {i + 1}: {descriptions[i]}")
            print(f"Input:    {digits}")
            print(f"Expected: {expected}")
            
            # Test all approaches
            result_optimized = PlusOneSolver.plus_one_optimized(digits.copy())
            result_carry = PlusOneSolver.plus_one_with_carry(digits.copy())
            result_convert = PlusOneSolver.plus_one_convert(digits.copy())
            result_recursive = PlusOneSolver.plus_one_recursive(digits.copy())
            
            print(f"Optimized Result:  {result_optimized}")
            print(f"Carry Result:      {result_carry}")
            print(f"Convert Result:    {result_convert}")
            print(f"Recursive Result:  {result_recursive}")
            
            # Verify correctness
            optimized_correct = result_optimized == expected
            carry_correct = result_carry == expected
            convert_correct = result_convert == expected
            recursive_correct = result_recursive == expected
            
            print(f"✅ Optimized:  {'PASSED' if optimized_correct else 'FAILED'}")
            print(f"✅ Carry:      {'PASSED' if carry_correct else 'FAILED'}")
            print(f"✅ Convert:    {'PASSED' if convert_correct else 'FAILED'}")
            print(f"✅ Recursive:  {'PASSED' if recursive_correct else 'FAILED'}")
            print("-" * 70)


def main():
    """Main function to run all test cases."""
    PlusOneSolver.run_test_cases()
    
    # Interactive example
    print("\n=== Interactive Example ===")
    sample_digits = [1, 9, 9]
    print(f"Adding 1 to number represented by: {sample_digits}")
    print(f"Number value: {''.join(map(str, sample_digits))}")
    
    # Show step-by-step process
    print("\nStep-by-step process (Optimized approach):")
    digits = sample_digits.copy()
    n = len(digits)
    
    for i in range(n - 1, -1, -1):
        print(f"\nStep {n - i}: Checking digit at index {i} (value: {digits[i]})")
        
        if digits[i] < 9:
            print(f"  ✅ Digit {digits[i]} < 9, increment it to {digits[i] + 1}")
            digits[i] += 1
            print(f"  Final result: {digits}")
            break
        else:
            print(f"  ⚠️  Digit is 9, set to 0 and carry over")
            digits[i] = 0
            print(f"  Current state: {digits} (carry continues)")
    else:
        print(f"\n  🔄 All digits were 9, prepending 1")
        digits = [1] + digits
        print(f"  Final result: {digits}")
    
    print(f"\nFinal number: {''.join(map(str, digits))}")
    
    # Edge cases demonstration
    print("\n=== Edge Cases Demonstration ===")
    edge_cases = [
        [9, 9, 9, 9],
        [1, 0, 0, 0],
        [5],
        [9]
    ]
    
    for case in edge_cases:
        result = PlusOneSolver.plus_one_optimized(case.copy())
        original_num = ''.join(map(str, case))
        result_num = ''.join(map(str, result))
        print(f"{original_num} + 1 = {result_num} → {result}")
    
    # Performance comparison
    print("\n=== Performance Analysis ===")
    print("For an array of n digits:")
    print("• Optimized Approach:  O(n) time, O(1) space* - Best for most cases")
    print("• Carry Approach:      O(n) time, O(n) space - More explicit")
    print("• Convert Approach:    O(n) time, O(n) space - Simple but limited")
    print("• Recursive Approach:  O(n) time, O(n) space - Educational")
    print("\n*O(1) when modifying in-place, O(n) when all digits are 9")
    
    print("\n=== Algorithm Explanation ===")
    print("The key insight:")
    print("1. Start from the rightmost (least significant) digit")
    print("2. If digit < 9: increment it and we're done")
    print("3. If digit = 9: set to 0 and continue to next digit (carry)")
    print("4. If all digits are 9: prepend 1 to the result")
    print("\nExample: [1,9,9] + 1")
    print("  Step 1: Last digit (9) → set to 0, carry → [1,9,0]")
    print("  Step 2: Middle digit (9) → set to 0, carry → [1,0,0]")
    print("  Step 3: First digit (1) → increment to 2 → [2,0,0]")


if __name__ == "__main__":
    main()
