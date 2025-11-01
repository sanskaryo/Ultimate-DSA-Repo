/**
 * Single Number
 * =============
 * 
 * Problem: Given a non-empty array of integers nums, every element appears twice 
 * except for one. Find that single one. You must implement a solution with a 
 * linear runtime complexity and use only constant extra space.
 * 
 * Approach 1 - XOR Bit Manipulation (Optimized):
 * - Use XOR operation: a ^ a = 0 and a ^ 0 = a
 * - XOR all elements together
 * - Duplicate numbers cancel out (become 0)
 * - Single number remains
 * 
 * Approach 2 - Hash Set:
 * - Use set to track seen numbers
 * - Add number if not seen, remove if already seen
 * - Remaining number is the single one
 * 
 * Time Complexity: O(n) for all approaches
 * Space Complexity: O(1) for XOR, O(n) for hash set
 */

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class SingleNumber {
    
    /**
     * Find single number using XOR bit manipulation.
     * 
     * @param nums Array of integers
     * @return The single number that appears only once
     * 
     * Example:
     *   Input: nums = [2, 2, 1]
     *   Output: 1
     *   
     *   Input: nums = [4, 1, 2, 1, 2]
     *   Output: 4
     */
    public static int singleNumberOptimized(int[] nums) {
        int result = 0;
        
        for (int num : nums) {
            result ^= num;
        }
        
        return result;
    }
    
    /**
     * Find single number using hash set.
     */
    public static int singleNumberHashSet(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        
        for (int num : nums) {
            if (seen.contains(num)) {
                seen.remove(num);
            } else {
                seen.add(num);
            }
        }
        
        return seen.iterator().next();
    }
    
    /**
     * Find single number using mathematical approach.
     */
    public static int singleNumberMath(int[] nums) {
        Set<Integer> uniqueNums = new HashSet<>();
        int sumAll = 0;
        
        for (int num : nums) {
            uniqueNums.add(num);
            sumAll += num;
        }
        
        int sumUnique = 0;
        for (int num : uniqueNums) {
            sumUnique += num;
        }
        
        return 2 * sumUnique - sumAll;
    }
    
    public static void printArray(int[] arr, String label) {
        System.out.print(label + ": [");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) System.out.print(", ");
        }
        System.out.println("]");
    }
    
    public static void runTestCases() {
        System.out.println("=== Single Number Test Results (Java) ===\n");
        
        int[][] inputs = {
            {2, 2, 1},
            {4, 1, 2, 1, 2},
            {1},
            {1, 3, 1, -1, 3},
            {0, 1, 0},
            {7, 3, 5, 3, 5},
            {-1, -1, -2},
            {100, 200, 100}
        };
        
        int[] expected = {1, 4, 1, -1, 1, 7, -2, 200};
        
        String[] descriptions = {
            "Basic case with three elements",
            "Multiple pairs with single number",
            "Single element array",
            "Negative number as single",
            "Zero in array",
            "Larger numbers",
            "All negative numbers",
            "Large value differences"
        };
        
        for (int i = 0; i < inputs.length; i++) {
            System.out.println("Test Case " + (i + 1) + ": " + descriptions[i]);
            
            printArray(inputs[i], "Input   ");
            System.out.println("Expected: " + expected[i]);
            
            int resultXOR = singleNumberOptimized(inputs[i]);
            int resultSet = singleNumberHashSet(inputs[i]);
            int resultMath = singleNumberMath(inputs[i]);
            
            System.out.println("XOR Result:      " + resultXOR);
            System.out.println("Hash Set Result: " + resultSet);
            System.out.println("Math Result:     " + resultMath);
            
            boolean xorCorrect = (resultXOR == expected[i]);
            boolean setCorrect = (resultSet == expected[i]);
            boolean mathCorrect = (resultMath == expected[i]);
            
            System.out.println("✅ XOR:      " + (xorCorrect ? "PASSED" : "FAILED"));
            System.out.println("✅ Hash Set: " + (setCorrect ? "PASSED" : "FAILED"));
            System.out.println("✅ Math:     " + (mathCorrect ? "PASSED" : "FAILED"));
            System.out.println("-".repeat(70));
        }
    }
    
    public static void main(String[] args) {
        runTestCases();
        
        System.out.println("\n=== Interactive Example ===");
        int[] sampleNums = {4, 1, 2, 1, 2};
        System.out.print("Finding single number in: ");
        printArray(sampleNums, "");
        
        System.out.println("\nStep-by-step XOR process:");
        int result = 0;
        
        for (int i = 0; i < sampleNums.length; i++) {
            int prevResult = result;
            result ^= sampleNums[i];
            System.out.println("Step " + (i + 1) + ": " + prevResult + " ^ " 
                + sampleNums[i] + " = " + result);
        }
        
        System.out.println("\nFinal single number: " + result);
        
        System.out.println("\n=== XOR Properties Explanation ===");
        System.out.println("Why XOR works:");
        System.out.println("1. a ^ a = 0  (same numbers cancel out)");
        System.out.println("2. a ^ 0 = a  (XOR with 0 gives the number)");
        System.out.println("3. XOR is commutative: a ^ b = b ^ a");
        System.out.println("4. XOR is associative: (a ^ b) ^ c = a ^ (b ^ c)");
        
        System.out.println("\n=== Performance Analysis ===");
        System.out.println("For an array of n elements:");
        System.out.println("• XOR Approach:      O(n) time, O(1) space - Optimal solution");
        System.out.println("• Hash Set Approach: O(n) time, O(n) space - Alternative");
        System.out.println("• Math Approach:     O(n) time, O(n) space - Mathematical");
    }
}
