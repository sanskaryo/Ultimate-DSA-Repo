/**
 * Move Zeroes
 * ===========
 * 
 * Problem: Given an integer array, move all 0's to the end while maintaining 
 * the relative order of non-zero elements. Must do this in-place.
 * 
 * Approach 1 - Two Pointers (Optimized):
 * - Use slow pointer to track position for next non-zero element
 * - Use fast pointer to scan through array
 * - When fast pointer finds non-zero element, place it at slow pointer position
 * - After placing all non-zeros, fill remaining positions with zeros
 * 
 * Approach 2 - Brute Force:
 * - Use additional array to store non-zero elements
 * - Copy non-zeros first, then fill remaining with zeros
 * - Copy back to original array
 * 
 * Time Complexity: O(n) for both approaches
 * Space Complexity: O(1) for two pointers, O(n) for brute force
 */

import java.util.*;

public class MoveZeroes {
    
    /**
     * Move all zeroes to end using two-pointer approach (in-place).
     * 
     * @param nums Array of integers (modified in-place)
     * 
     * Example:
     *   Input: nums = [0, 1, 0, 3, 12]
     *   Output: nums = [1, 3, 12, 0, 0]
     *   Explanation: Non-zeros maintain relative order, zeros moved to end
     */
    public static void moveZeroesOptimized(int[] nums) {
        // Handle edge case - empty array or single element
        if (nums.length <= 1) {
            return;
        }
        
        // Slow pointer - tracks position for next non-zero element
        int slowPointer = 0;
        
        // Fast pointer - scans through array to find non-zero elements
        for (int fastPointer = 0; fastPointer < nums.length; fastPointer++) {
            // If current element is non-zero
            if (nums[fastPointer] != 0) {
                // Place non-zero element at slow pointer position
                nums[slowPointer] = nums[fastPointer];
                // Move slow pointer to next position
                slowPointer++;
            }
        }
        
        // Fill remaining positions with zeros
        for (int i = slowPointer; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
    
    /**
     * Alternative optimized approach using swapping.
     * Maintains relative order and minimizes writes.
     */
    public static void moveZeroesSwapOptimized(int[] nums) {
        if (nums.length <= 1) {
            return;
        }
        
        // Position for next non-zero element
        int nonZeroPos = 0;
        
        // Move all non-zero elements to front
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                // Swap only if positions are different
                if (i != nonZeroPos) {
                    int temp = nums[nonZeroPos];
                    nums[nonZeroPos] = nums[i];
                    nums[i] = temp;
                }
                nonZeroPos++;
            }
        }
    }
    
    /**
     * Move zeroes using additional space for comparison.
     * Time: O(n), Space: O(n)
     * Helps understand the problem better.
     */
    public static void moveZeroesBruteForce(int[] nums) {
        if (nums.length <= 1) {
            return;
        }
        
        // Store non-zero elements
        List<Integer> nonZeroElements = new ArrayList<>();
        int zeroCount = 0;
        
        // Separate non-zeros and count zeros
        for (int num : nums) {
            if (num != 0) {
                nonZeroElements.add(num);
            } else {
                zeroCount++;
            }
        }
        
        // Fill array: non-zeros first, then zeros
        for (int i = 0; i < nonZeroElements.size(); i++) {
            nums[i] = nonZeroElements.get(i);
        }
        
        for (int i = nonZeroElements.size(); i < nums.length; i++) {
            nums[i] = 0;
        }
    }
    
    /**
     * Print array in readable format
     */
    public static void printArray(int[] arr) {
        System.out.print("[");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) System.out.print(", ");
        }
        System.out.print("]");
    }
    
    /**
     * Print before and after arrays to show the transformation
     */
    public static void printArrayChanges(int[] original, int[] result, String method) {
        System.out.println(method + ":");
        System.out.print("  Before: ");
        printArray(original);
        System.out.println();
        System.out.print("  After:  ");
        printArray(result);
        System.out.println();
    }
    
    /**
     * Verify if the result matches expected output
     */
    public static boolean verifyResult(int[] nums, int[] expected) {
        return Arrays.equals(nums, expected);
    }
    
    /**
     * Run comprehensive test cases for all approaches
     */
    public static void runTestCases() {
        System.out.println("=== Move Zeroes Test Results ===\n");
        
        // Test cases with expected results
        int[][] testCases = {
            {0, 1, 0, 3, 12},
            {0, 0, 1},
            {1, 0, 0},
            {0, 0, 0},
            {1, 2, 3},
            {0},
            {5},
            {0, 1},
            {1, 0}
        };
        
        int[][] expectedResults = {
            {1, 3, 12, 0, 0},
            {1, 0, 0},
            {1, 0, 0},
            {0, 0, 0},
            {1, 2, 3},
            {0},
            {5},
            {1, 0},
            {1, 0}
        };
        
        String[] descriptions = {
            "Mixed zeros and non-zeros",
            "Leading zeros case",
            "Trailing zeros case",
            "All zeros case",
            "No zeros present",
            "Single zero element",
            "Single non-zero element",
            "Two elements - zero first",
            "Two elements - zero last"
        };
        
        for (int i = 0; i < testCases.length; i++) {
            int[] originalNums = testCases[i];
            int[] expected = expectedResults[i];
            
            System.out.println("Test Case " + (i + 1) + ": " + descriptions[i]);
            System.out.print("Input: ");
            printArray(originalNums);
            System.out.println();
            System.out.print("Expected: ");
            printArray(expected);
            System.out.println();
            
            // Test optimized approach
            int[] numsOptimized = originalNums.clone();
            moveZeroesOptimized(numsOptimized);
            printArrayChanges(originalNums, numsOptimized, "Optimized (Two Pointers)");
            
            // Test swap approach
            int[] numsSwap = originalNums.clone();
            moveZeroesSwapOptimized(numsSwap);
            printArrayChanges(originalNums, numsSwap, "Optimized (Swapping)");
            
            // Test brute force approach
            int[] numsBruteForce = originalNums.clone();
            moveZeroesBruteForce(numsBruteForce);
            printArrayChanges(originalNums, numsBruteForce, "Brute Force");
            
            // Verify correctness
            boolean optimizedCorrect = verifyResult(numsOptimized, expected);
            boolean swapCorrect = verifyResult(numsSwap, expected);
            boolean bruteForceCorrect = verifyResult(numsBruteForce, expected);
            
            System.out.println("✅ Two Pointers: " + (optimizedCorrect ? "PASSED" : "FAILED"));
            System.out.println("✅ Swapping: " + (swapCorrect ? "PASSED" : "FAILED"));
            System.out.println("✅ Brute Force: " + (bruteForceCorrect ? "PASSED" : "FAILED"));
            System.out.println("-".repeat(70));
        }
    }
    
    /**
     * Main method to run all test cases and interactive example
     */
    public static void main(String[] args) {
        runTestCases();
        
        // Interactive example
        System.out.println("\n=== Interactive Example ===");
        int[] sampleNums = {0, 1, 0, 3, 12, 0, 5};
        System.out.print("Original array: ");
        printArray(sampleNums);
        System.out.println();
        
        // Show step-by-step process for two-pointer approach
        System.out.println("\nStep-by-step process (Two Pointers):");
        int[] numsCopy = sampleNums.clone();
        int slow = 0;
        System.out.print("Initial: slow=0, array=");
        printArray(numsCopy);
        System.out.println();
        
        // Phase 1: Move non-zeros to front
        for (int fast = 0; fast < numsCopy.length; fast++) {
            if (numsCopy[fast] != 0) {
                numsCopy[slow] = numsCopy[fast];
                slow++;
                System.out.print("Found non-zero " + numsCopy[fast] + ": slow=" + slow + ", array=");
                printArray(numsCopy);
                System.out.println();
            }
        }
        
        // Phase 2: Fill remaining with zeros
        int originalSlow = slow;
        for (int i = slow; i < numsCopy.length; i++) {
            numsCopy[i] = 0;
        }
        
        System.out.println("\nAfter filling remaining " + (numsCopy.length - originalSlow) 
                         + " positions with zeros:");
        System.out.print("Final result: ");
        printArray(numsCopy);
        System.out.println();
    }
}
