/**
 * Remove Duplicates from Sorted Array
 * ===================================
 * 
 * Problem: Given a sorted array, remove duplicates in-place and return the new length.
 * The relative order of elements should be kept the same.
 * 
 * Approach 1 - Two Pointers (Optimized):
 * - Use slow pointer to track position for next unique element
 * - Use fast pointer to scan through array
 * - When fast pointer finds new unique element, place it at slow pointer position
 * - Increment slow pointer only when we place a new unique element
 * 
 * Approach 2 - Brute Force:
 * - Use additional space to track unique elements
 * - Not optimal for in-place requirement but helps understand the problem
 * 
 * Time Complexity: O(n) for two pointers, O(n) for brute force
 * Space Complexity: O(1) for two pointers, O(n) for brute force
 */

import java.util.*;

public class RemoveDuplicatesSortedArray {
    
    /**
     * Remove duplicates from sorted array using two-pointer approach.
     * 
     * @param nums Sorted array of integers (modified in-place)
     * @return Length of array after removing duplicates
     * 
     * Example:
     *   Input: nums = [1, 1, 2]
     *   Output: 2, and nums = [1, 2, _]
     *   Explanation: First 2 elements are unique
     */
    public static int removeDuplicatesOptimized(int[] nums) {
        // Handle edge case - empty array
        if (nums.length == 0) {
            return 0;
        }
        
        // Slow pointer - tracks position for next unique element
        int slowPointer = 0;
        
        // Fast pointer - scans through array starting from index 1
        for (int fastPointer = 1; fastPointer < nums.length; fastPointer++) {
            // If current element is different from previous unique element
            if (nums[fastPointer] != nums[slowPointer]) {
                // Move slow pointer to next position
                slowPointer++;
                // Place the new unique element at slow pointer position
                nums[slowPointer] = nums[fastPointer];
            }
        }
        
        // Return length of unique elements (slowPointer + 1)
        return slowPointer + 1;
    }
    
    /**
     * Remove duplicates using additional space for comparison.
     * Time: O(n), Space: O(n)
     * Not optimal for in-place requirement but helps understand problem.
     */
    public static int removeDuplicatesBruteForce(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        
        // Track unique elements
        List<Integer> uniqueElements = new ArrayList<>();
        
        // Add first element (always unique in sorted array)
        uniqueElements.add(nums[0]);
        
        // Check each element against the last unique element
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != uniqueElements.get(uniqueElements.size() - 1)) {
                uniqueElements.add(nums[i]);
            }
        }
        
        // Copy unique elements back to original array
        for (int i = 0; i < uniqueElements.size(); i++) {
            nums[i] = uniqueElements.get(i);
        }
        
        return uniqueElements.size();
    }
    
    /**
     * Print array showing only the valid elements up to given length
     */
    public static void printArrayWithLength(int[] nums, int length) {
        System.out.print("[");
        for (int i = 0; i < nums.length; i++) {
            if (i < length) {
                System.out.print(nums[i]);
            } else {
                System.out.print("_");
            }
            if (i < nums.length - 1) System.out.print(", ");
        }
        System.out.print("]");
    }
    
    /**
     * Print regular array
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
     * Verify if result is correct
     */
    public static boolean verifyResult(int[] nums, int resultLength, 
                                     int[] expected, int expectedLength) {
        if (resultLength != expectedLength) return false;
        for (int i = 0; i < expectedLength; i++) {
            if (nums[i] != expected[i]) return false;
        }
        return true;
    }
    
    /**
     * Run comprehensive test cases for both approaches
     */
    public static void runTestCases() {
        System.out.println("=== Remove Duplicates from Sorted Array Test Results ===\n");
        
        // Test cases with expected results
        int[][] testCases = {
            {1, 1, 2},
            {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
            {1, 2, 3, 4, 5},
            {1},
            {2, 2, 2, 2},
            new int[]{}
        };
        
        int[] expectedLengths = {2, 5, 5, 1, 1, 0};
        
        int[][] expectedUnique = {
            {1, 2},
            {0, 1, 2, 3, 4},
            {1, 2, 3, 4, 5},
            {1},
            {2},
           new int[]{}
        };
        
        String[] descriptions = {
            "Basic case with some duplicates",
            "Multiple consecutive duplicates", 
            "No duplicates present",
            "Single element array",
            "All elements are same",
            "Empty array edge case"
        };
        
        for (int i = 0; i < testCases.length; i++) {
            int[] originalNums = testCases[i];
            int expectedLength = expectedLengths[i];
            int[] expectedUniqueElements = expectedUnique[i];
            
            System.out.println("Test Case " + (i + 1) + ": " + descriptions[i]);
            System.out.print("Input: ");
            printArray(originalNums);
            System.out.println();
            System.out.println("Expected Length: " + expectedLength);
            System.out.print("Expected Unique Elements: ");
            printArray(expectedUniqueElements);
            System.out.println();
            
            // Test optimized approach
            int[] numsOptimized = originalNums.clone();
            int resultLengthOptimized = removeDuplicatesOptimized(numsOptimized);
            
            System.out.println("Optimized Result Length: " + resultLengthOptimized);
            System.out.print("Optimized Result Array: ");
            printArrayWithLength(numsOptimized, resultLengthOptimized);
            System.out.println();
            
            // Test brute force approach
            int[] numsBruteForce = originalNums.clone();
            int resultLengthBruteForce = removeDuplicatesBruteForce(numsBruteForce);
            
            System.out.println("Brute Force Result Length: " + resultLengthBruteForce);
            System.out.print("Brute Force Result Array: ");
            printArrayWithLength(numsBruteForce, resultLengthBruteForce);
            System.out.println();
            
            // Verify correctness
            boolean optimizedCorrect = verifyResult(numsOptimized, resultLengthOptimized, 
                                                  expectedUniqueElements, expectedLength);
            boolean bruteForceCorrect = verifyResult(numsBruteForce, resultLengthBruteForce, 
                                                   expectedUniqueElements, expectedLength);
            
            System.out.println("✅ Optimized: " + (optimizedCorrect ? "PASSED" : "FAILED"));
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
        int[] sampleNums = {1, 1, 2, 2, 3, 4, 4, 5};
        System.out.print("Original array: ");
        printArray(sampleNums);
        System.out.println();
        
        // Show step-by-step process
        System.out.println("\nStep-by-step process:");
        int[] numsCopy = sampleNums.clone();
        int slow = 0;
        System.out.print("Initial: slow=0, array=");
        printArray(numsCopy);
        System.out.println();
        
        for (int fast = 1; fast < numsCopy.length; fast++) {
            if (numsCopy[fast] != numsCopy[slow]) {
                slow++;
                numsCopy[slow] = numsCopy[fast];
                System.out.print("Found unique " + numsCopy[fast] + ": slow=" + slow + ", array=");
                printArray(numsCopy);
                System.out.println();
            }
        }
        
        int newLength = slow + 1;
        System.out.println("\nFinal result:");
        System.out.println("New length: " + newLength);
        System.out.print("Array after removing duplicates: ");
        printArrayWithLength(numsCopy, newLength);
        System.out.println();
    }
}
