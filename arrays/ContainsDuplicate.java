/**
 * Contains Duplicate
 * ==================
 * 
 * Problem: Given an integer array, return true if any value appears at least twice 
 * in the array, and return false if every element is distinct.
 * 
 * Approach 1 - Hash Set (Optimized):
 * - Use HashSet to store elements as we iterate
 * - For each element, check if it already exists in the set
 * - If found, return true (duplicate found)
 * - If not found, add element to set and continue
 * - If we finish iteration without finding duplicates, return false
 * 
 * Approach 2 - Sorting:
 * - Sort the array first
 * - Check adjacent elements for duplicates
 * - If any adjacent pair is equal, return true
 * 
 * Approach 3 - Brute Force:
 * - For each element, check all other elements for duplicates
 * - Nested loop approach
 * 
 * Time Complexity: O(n) for hash set, O(n log n) for sorting, O(n²) for brute force
 * Space Complexity: O(n) for hash set, O(1) for sorting, O(1) for brute force
 */

import java.util.*;

public class ContainsDuplicate {
    
    /**
     * Check for duplicates using hash set approach.
     * 
     * @param nums Array of integers
     * @return True if duplicates exist, false otherwise
     * 
     * Example:
     *   Input: nums = [1, 2, 3, 1]
     *   Output: true (1 appears twice)
     */
    public static boolean containsDuplicateOptimized(int[] nums) {
        // Hash set to store seen elements
        Set<Integer> seenElements = new HashSet<>();
        
        // Check each element
        for (int num : nums) {
            // If element already exists in set, we found a duplicate
            if (seenElements.contains(num)) {
                return true;
            }
            // Add current element to set
            seenElements.add(num);
        }
        
        // No duplicates found
        return false;
    }
    
    /**
     * Check for duplicates using sorting approach.
     * Time: O(n log n), Space: O(1)
     */
    public static boolean containsDuplicateSorting(int[] nums) {
        if (nums.length <= 1) {
            return false;
        }
        
        // Sort the array (creates a copy to avoid modifying original)
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);
        
        // Check adjacent elements
        for (int i = 1; i < sortedNums.length; i++) {
            if (sortedNums[i] == sortedNums[i - 1]) {
                return true;
            }
        }
        
        return false;
    }
    
    /**
     * Check for duplicates using brute force approach.
     * Time: O(n²), Space: O(1)
     * Helps understand the problem better.
     */
    public static boolean containsDuplicateBruteForce(int[] nums) {
        int arrayLength = nums.length;
        
        // Check each pair of elements
        for (int i = 0; i < arrayLength; i++) {
            for (int j = i + 1; j < arrayLength; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    /**
     * Bonus function: Find the first duplicate element.
     * Returns the first element that appears twice, or -1 if no duplicates.
     */
    public static int findFirstDuplicate(int[] nums) {
        Set<Integer> seenElements = new HashSet<>();
        
        for (int num : nums) {
            if (seenElements.contains(num)) {
                return num;
            }
            seenElements.add(num);
        }
        
        return -1; // No duplicate found
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
     * Print set in readable format
     */
    public static void printSet(Set<Integer> set) {
        System.out.print("{");
        boolean first = true;
        for (int elem : set) {
            if (!first) System.out.print(", ");
            System.out.print(elem);
            first = false;
        }
        System.out.print("}");
    }
    
    /**
     * Run comprehensive test cases for all approaches
     */
    public static void runTestCases() {
        System.out.println("=== Contains Duplicate Test Results ===\n");
        
        // Test cases with expected results
        int[][] testCases = {
            {1, 2, 3, 1},
            {1, 2, 3, 4},
            {1, 1, 1, 3, 3, 4, 3, 2, 4, 2},
            {1},
            {},
            {0, 0},
            {-1, -2, -3, -1},
            {1000000, 999999, 1000000},
            {1, 2, 3, 4, 5, 6, 7, 8, 9}
        };
        
        boolean[] expectedResults = {
            true, false, true, false, false, true, true, true, false
        };
        
        String[] descriptions = {
            "Basic case with duplicate at different positions",
            "No duplicates present", 
            "Multiple different duplicates",
            "Single element array",
            "Empty array edge case",
            "Two identical elements",
            "Negative numbers with duplicates",
            "Large numbers case",
            "Longer array without duplicates"
        };
        
        for (int i = 0; i < testCases.length; i++) {
            int[] nums = testCases[i];
            boolean expected = expectedResults[i];
            
            System.out.println("Test Case " + (i + 1) + ": " + descriptions[i]);
            System.out.print("Input: ");
            printArray(nums);
            System.out.println();
            System.out.println("Expected: " + expected);
            
            // Test all approaches
            boolean resultOptimized = containsDuplicateOptimized(nums);
            boolean resultSorting = containsDuplicateSorting(nums);
            boolean resultBruteForce = containsDuplicateBruteForce(nums);
            
            System.out.println("Hash Set Result: " + resultOptimized);
            System.out.println("Sorting Result: " + resultSorting);
            System.out.println("Brute Force Result: " + resultBruteForce);
            
            // Find first duplicate if it exists
            if (expected) {
                int firstDuplicate = findFirstDuplicate(nums);
                System.out.println("First Duplicate Found: " + firstDuplicate);
            }
            
            // Verify correctness
            boolean optimizedCorrect = resultOptimized == expected;
            boolean sortingCorrect = resultSorting == expected;
            boolean bruteForceCorrect = resultBruteForce == expected;
            
            System.out.println("✅ Hash Set: " + (optimizedCorrect ? "PASSED" : "FAILED"));
            System.out.println("✅ Sorting: " + (sortingCorrect ? "PASSED" : "FAILED"));
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
        int[] sampleNums = {1, 3, 2, 4, 3, 5};
        System.out.print("Checking array: ");
        printArray(sampleNums);
        System.out.println();
        
        // Show step-by-step process for hash set approach
        System.out.println("\nStep-by-step process (Hash Set approach):");
        Set<Integer> seen = new HashSet<>();
        
        for (int i = 0; i < sampleNums.length; i++) {
            int num = sampleNums[i];
            System.out.println("Step " + (i + 1) + ": Checking element " + num);
            
            if (seen.contains(num)) {
                System.out.println("  ❌ Element " + num + " already seen! Duplicate found.");
                System.out.print("  Seen elements so far: ");
                printSet(seen);
                System.out.println();
                break;
            } else {
                seen.add(num);
                System.out.println("  ✅ Element " + num + " is new. Adding to seen set.");
                System.out.print("  Seen elements so far: ");
                printSet(seen);
                System.out.println();
            }
        }
        
        // Performance comparison
        System.out.println("\n=== Performance Analysis ===");
        System.out.println("For an array of size n:");
        System.out.println("• Hash Set:    O(n) time, O(n) space - Best for most cases");
        System.out.println("• Sorting:     O(n log n) time, O(1) space - Good when space is limited");
        System.out.println("• Brute Force: O(n²) time, O(1) space - Only for very small arrays");
    }
}
