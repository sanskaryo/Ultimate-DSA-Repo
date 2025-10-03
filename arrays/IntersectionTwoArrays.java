/**
 * Intersection of Two Arrays
 * ==========================
 * 
 * Problem: Given two integer arrays, return an array of their intersection. 
 * Each element in the result must be unique and you may return the result in any order.
 * 
 * Approach 1 - Hash Set (Optimized):
 * - Convert first array to HashSet for O(1) lookups
 * - Iterate through second array and check if each element exists in the set
 * - Add elements that exist in both arrays to result set
 * - Convert result set back to array
 * 
 * Approach 2 - Sorting + Two Pointers:
 * - Sort both arrays first
 * - Use two pointers to find common elements
 * - Skip duplicates while iterating
 * 
 * Approach 3 - Brute Force:
 * - For each element in first array, check if it exists in second array
 * - Use set to avoid duplicate results
 * 
 * Time Complexity: O(n + m) for hash set, O(n log n + m log m) for sorting
 * Space Complexity: O(min(n, m)) for hash set, O(1) for sorting (excluding result)
 */

import java.util.*;

public class IntersectionTwoArrays {
    
    /**
     * Find intersection using hash set approach.
     * 
     * @param nums1 First array of integers
     * @param nums2 Second array of integers
     * @return Array containing unique elements present in both arrays
     * 
     * Example:
     *   Input: nums1 = [1, 2, 2, 1], nums2 = [2, 2]
     *   Output: [2]
     */
    public static int[] intersectionOptimized(int[] nums1, int[] nums2) {
        // Convert first array to set for O(1) lookups
        Set<Integer> set1 = new HashSet<>();
        for (int num : nums1) {
            set1.add(num);
        }
        
        // Set to store intersection results (automatically handles uniqueness)
        Set<Integer> intersectionSet = new HashSet<>();
        
        // Check each element in second array
        for (int num : nums2) {
            // If element exists in first array, add to result
            if (set1.contains(num)) {
                intersectionSet.add(num);
            }
        }
        
        // Convert set back to array
        return intersectionSet.stream().mapToInt(Integer::intValue).toArray();
    }
    
    /**
     * Find intersection using sorting + two pointers approach.
     * Time: O(n log n + m log m), Space: O(1) excluding result
     */
    public static int[] intersectionSorting(int[] nums1, int[] nums2) {
        // Sort both arrays
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        // Two pointers and result set
        int i = 0, j = 0;
        Set<Integer> intersectionSet = new HashSet<>();
        
        // Use two pointers to find common elements
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] == nums2[j]) {
                // Found common element
                intersectionSet.add(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return intersectionSet.stream().mapToInt(Integer::intValue).toArray();
    }
    
    /**
     * Find intersection using brute force approach.
     * Time: O(n * m), Space: O(min(n, m))
     * Helps understand the problem better.
     */
    public static int[] intersectionBruteForce(int[] nums1, int[] nums2) {
        Set<Integer> intersectionSet = new HashSet<>();
        
        // Check each element in first array
        for (int num1 : nums1) {
            // Check if it exists in second array
            for (int num2 : nums2) {
                if (num1 == num2) {
                    intersectionSet.add(num1);
                    break; // Found it, no need to check further
                }
            }
        }
        
        return intersectionSet.stream().mapToInt(Integer::intValue).toArray();
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
     * Sort array for comparison (since order doesn't matter in intersection)
     */
    public static int[] sortArray(int[] arr) {
        int[] sorted = arr.clone();
        Arrays.sort(sorted);
        return sorted;
    }
    
    /**
     * Run comprehensive test cases for all approaches
     */
    public static void runTestCases() {
        System.out.println("=== Intersection of Two Arrays Test Results ===\n");
        
        // Test cases with expected results
        int[][] testCases1 = {
            {1, 2, 2, 1},
            {4, 9, 5},
            {1, 2, 3},
            {1, 2, 3, 4, 5},
            {1},
            {1},
            {},
            {1, 2, 3},
            {},
            {1, 1, 1}
        };
        
        int[][] testCases2 = {
            {2, 2},
            {9, 4, 9, 8, 4},
            {4, 5, 6},
            {3, 4, 5, 6, 7},
            {1},
            {2},
            {1, 2, 3},
            {},
            {},
            {1, 1, 1}
        };
        
        int[][] expectedResults = {
            {2},
            {4, 9},
            {},
            {3, 4, 5},
            {1},
            {},
            {},
            {},
            {},
            {1}
        };
        
        String[] descriptions = {
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
        };
        
        for (int i = 0; i < testCases1.length; i++) {
            int[] nums1 = testCases1[i];
            int[] nums2 = testCases2[i];
            int[] expected = sortArray(expectedResults[i]);
            
            System.out.println("Test Case " + (i + 1) + ": " + descriptions[i]);
            System.out.print("Input: nums1 = ");
            printArray(nums1);
            System.out.print(", nums2 = ");
            printArray(nums2);
            System.out.println();
            System.out.print("Expected: ");
            printArray(expected);
            System.out.println();
            
            // Test all approaches
            int[] resultOptimized = sortArray(intersectionOptimized(nums1.clone(), nums2.clone()));
            int[] resultSorting = sortArray(intersectionSorting(nums1.clone(), nums2.clone()));
            int[] resultBruteForce = sortArray(intersectionBruteForce(nums1.clone(), nums2.clone()));
            
            System.out.print("Hash Set Result: ");
            printArray(resultOptimized);
            System.out.println();
            System.out.print("Sorting Result: ");
            printArray(resultSorting);
            System.out.println();
            System.out.print("Brute Force Result: ");
            printArray(resultBruteForce);
            System.out.println();
            
            // Verify correctness
            boolean optimizedCorrect = Arrays.equals(resultOptimized, expected);
            boolean sortingCorrect = Arrays.equals(resultSorting, expected);
            boolean bruteForceCorrect = Arrays.equals(resultBruteForce, expected);
            
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
        int[] nums1 = {1, 2, 2, 1, 3, 4};
        int[] nums2 = {2, 2, 3, 5, 6};
        System.out.print("Finding intersection of ");
        printArray(nums1);
        System.out.print(" and ");
        printArray(nums2);
        System.out.println();
        
        // Show step-by-step process for hash set approach
        System.out.println("\nStep-by-step process (Hash Set approach):");
        Set<Integer> set1 = new HashSet<>();
        for (int num : nums1) {
            set1.add(num);
        }
        System.out.print("Step 1: Convert nums1 to set: ");
        printSet(set1);
        System.out.println();
        
        Set<Integer> intersectionSet = new HashSet<>();
        System.out.println("Step 2: Check each element in nums2:");
        
        for (int i = 0; i < nums2.length; i++) {
            int num = nums2[i];
            System.out.print("  Check " + num + ": ");
            if (set1.contains(num)) {
                intersectionSet.add(num);
                System.out.print("✅ Found in nums1, added to result. Result so far: ");
                printSet(intersectionSet);
                System.out.println();
            } else {
                System.out.println("❌ Not in nums1, skipping.");
            }
        }
        
        int[] result = intersectionSet.stream().mapToInt(Integer::intValue).toArray();
        System.out.print("\nFinal intersection: ");
        printArray(result);
        System.out.println();
        
        // Performance comparison
        System.out.println("\n=== Performance Analysis ===");
        System.out.println("For arrays of size n and m:");
        System.out.println("• Hash Set:     O(n + m) time, O(min(n,m)) space - Best general approach");
        System.out.println("• Sorting:      O(n log n + m log m) time, O(1) space - Good for sorted data");
        System.out.println("• Brute Force:  O(n * m) time, O(min(n,m)) space - Only for small arrays");
    }
}
