/**
 * Two Sum Problem
 * ===============
 * 
 * Problem: Given an array of integers and a target sum, return indices of two numbers 
 * that add up to the target. Assume exactly one solution exists.
 * 
 * Approach 1 - HashMap (Optimized):
 * - Use HashMap to store numbers and their indices as we iterate
 * - For each number, check if (target - current_number) exists in HashMap
 * - If found, return both indices
 * - If not found, add current number and index to HashMap
 * 
 * Approach 2 - Brute Force:
 * - Try all possible pairs using nested loops
 * - Check if each pair sums to target
 * 
 * Time Complexity: O(n) for HashMap, O(n²) for brute force
 * Space Complexity: O(n) for HashMap, O(1) for brute force
 */

import java.util.*;

public class TwoSum {
    
    /**
     * Find two numbers that add up to target using HashMap approach.
     * 
     * @param nums Array of integers
     * @param target Target sum we want to achieve
     * @return Array containing indices of the two numbers that sum to target
     * 
     * Example:
     *   Input: nums = [2, 7, 11, 15], target = 9
     *   Output: [0, 1] (because nums[0] + nums[1] = 2 + 7 = 9)
     */
    public static int[] twoSumOptimized(int[] nums, int target) {
        // HashMap to store number -> index mapping
        Map<Integer, Integer> numToIndex = new HashMap<>();
        
        // Iterate through the array with index
        for (int currentIndex = 0; currentIndex < nums.length; currentIndex++) {
            int currentNum = nums[currentIndex];
            
            // Calculate what number we need to reach the target
            int neededNum = target - currentNum;
            
            // Check if the needed number exists in our HashMap
            if (numToIndex.containsKey(neededNum)) {
                // Found the pair! Return indices
                return new int[]{numToIndex.get(neededNum), currentIndex};
            }
            
            // Store current number and its index for future lookups
            numToIndex.put(currentNum, currentIndex);
        }
        
        // This should never happen if problem guarantees a solution exists
        return new int[]{};
    }
    
    /**
     * Find two numbers that add up to target using brute force approach.
     * Time: O(n²), Space: O(1)
     * Useful for understanding the problem better.
     */
    public static int[] twoSumBruteForce(int[] nums, int target) {
        int arrayLength = nums.length;
        
        // Try all possible pairs
        for (int firstIndex = 0; firstIndex < arrayLength - 1; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < arrayLength; secondIndex++) {
                // Check if current pair sums to target
                if (nums[firstIndex] + nums[secondIndex] == target) {
                    return new int[]{firstIndex, secondIndex};
                }
            }
        }
        
        // No solution found
        return new int[]{};
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
     * Verify if the result indices give the correct sum
     */
    public static boolean verifyResult(int[] nums, int[] result, int target) {
        if (result.length != 2) return false;
        return nums[result[0]] + nums[result[1]] == target;
    }
    
    /**
     * Run comprehensive test cases for both approaches
     */
    public static void runTestCases() {
        System.out.println("=== Two Sum Problem Test Results ===\n");
        
        // Test cases with expected results
        int[][] testNums = {
            {2, 7, 11, 15},
            {3, 2, 4},
            {3, 3},
            {1, 5, 3, 8, 2},
            {-1, -2, -3, -4, -5}
        };
        
        int[] testTargets = {9, 6, 6, 10, -8};
        
        int[][] expectedResults = {
            {0, 1},
            {1, 2},
            {0, 1},
            {1, 3},
            {2, 4}
        };
        
        String[] descriptions = {
            "Basic case - first two elements sum to target",
            "Target requires elements from middle and end",
            "Duplicate numbers that sum to target",
            "Array with multiple valid pairs",
            "Negative numbers case"
        };
        
        for (int i = 0; i < testNums.length; i++) {
            int[] nums = testNums[i];
            int target = testTargets[i];
            int[] expected = expectedResults[i];
            
            System.out.println("Test Case " + (i + 1) + ": " + descriptions[i]);
            System.out.print("Input: nums = ");
            printArray(nums);
            System.out.println(", target = " + target);
            System.out.print("Expected: ");
            printArray(expected);
            System.out.println();
            
            // Test optimized approach
            int[] resultOptimized = twoSumOptimized(nums.clone(), target);
            System.out.print("Optimized Result: ");
            printArray(resultOptimized);
            System.out.println();
            
            // Test brute force approach
            int[] resultBruteForce = twoSumBruteForce(nums.clone(), target);
            System.out.print("Brute Force Result: ");
            printArray(resultBruteForce);
            System.out.println();
            
            // Verify correctness
            boolean optimizedCorrect = verifyResult(nums, resultOptimized, target);
            boolean bruteForceCorrect = verifyResult(nums, resultBruteForce, target);
            
            System.out.println("✅ Optimized: " + (optimizedCorrect ? "PASSED" : "FAILED"));
            System.out.println("✅ Brute Force: " + (bruteForceCorrect ? "PASSED" : "FAILED"));
            System.out.println("-".repeat(60));
        }
    }
    
    /**
     * Main method to run all test cases and interactive example
     */
    public static void main(String[] args) {
        runTestCases();
        
        // Interactive example
        System.out.println("\n=== Interactive Example ===");
        int[] sampleNums = {2, 7, 11, 15};
        int sampleTarget = 9;
        
        System.out.print("Finding two numbers in ");
        printArray(sampleNums);
        System.out.println(" that sum to " + sampleTarget);
        
        int[] result = twoSumOptimized(sampleNums, sampleTarget);
        
        if (result.length > 0) {
            System.out.print("Found at indices: ");
            printArray(result);
            System.out.println();
            System.out.println("Numbers: " + sampleNums[result[0]] + " + " 
                             + sampleNums[result[1]] + " = " + sampleTarget);
        } else {
            System.out.println("No solution found!");
        }
    }
}