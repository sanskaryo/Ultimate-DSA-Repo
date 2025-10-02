import java.util.*;

public class ThreeSum {
    
    /**
     * Brute Force Approach (O(n^3))
     * 
     * Simply check all possible triplets.
     * 
     * Time Complexity: O(n^3)
     * Space Complexity: O(1)
     */
    public static List<Integer> threeSumBruteForce(int[] nums, int target) {
        int n = nums.length;
        
        // Need at least 3 elements
        if (n < 3) {
            // return an empty array
            return new ArrayList<>();
        }

        // Try all possible combinations of three different indices
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {            // j starts after i to avoid duplicates
                for (int k = j + 1; k < n; k++) {        // k starts after j to avoid duplicates
                    // Check if current triplet sums to target
                    if (nums[i] + nums[j] + nums[k] == target) {
                        return Arrays.asList(i, j, k);   // Return indices of the triplet
                    }
                }
            }
        }
        return new ArrayList<>();  // No triplet found
    }
    
    /**
     * Optimal Hash Map Approach (O(n^2))
     * 
     * For each element, reduce the problem to a Two Sum (target - nums[i]).
     * Use a HashMap to store complements.
     * 
     * Time Complexity: O(n^2)
     * Space Complexity: O(n)
     */
    public static List<Integer> threeSum(int[] nums, int target) {
        int n = nums.length;

        // Need at least 3 elements
        if (n < 3) {
            // return an empty array
            return new ArrayList<>();
        }
        
        // Fix the first element and solve Two Sum for the remaining elements
        for (int i = 0; i < n; i++) {
            Map<Integer, Integer> seen = new HashMap<>();  // Maps value to its index
            int newTarget = target - nums[i];              // What the other two numbers should sum to
            
            // Look for two numbers that sum to newTarget in the remaining array
            for (int j = i + 1; j < n; j++) {
                int complement = newTarget - nums[j];       // What we need to complete the triplet
                
                // Check if we've seen the complement before
                if (seen.containsKey(complement)) {
                    // Found triplet: nums[i] + nums[seen.get(complement)] + nums[j] = target
                    return Arrays.asList(i, seen.get(complement), j);
                }
                
                // Store current number and its index for future lookups
                seen.put(nums[j], j);
            }
        }
        
        return new ArrayList<>();  // No triplet found
    }
    
    // --- Test Cases ---
    public static void main(String[] args) {
        // Test Case 1: Basic positive numbers with valid triplet
        // Expected: indices where nums[i] + nums[j] + nums[k] = 20
        // Array: [2, 7, 11, 15, -2], Target: 20
        // Solution: 2 + 7 + 11 = 20 (indices 0, 1, 2)
        int[] nums1 = {2, 7, 11, 15, -2};
        int target1 = 20;
        List<Integer> result1 = threeSum(nums1, target1);
        if (!result1.isEmpty()) {
            System.out.println("Test 1 - Optimal: " + result1);
            System.out.println("Values: " + nums1[result1.get(0)] + " + " + 
                             nums1[result1.get(1)] + " + " + nums1[result1.get(2)] + " = " + target1);
        }
        
        List<Integer> brute1 = threeSumBruteForce(nums1, target1);
        if (!brute1.isEmpty()) {
            System.out.println("Test 1 - Brute: " + brute1);
        }
        
        // Test Case 2: Another set with valid triplet
        // Expected: indices where nums[i] + nums[j] + nums[k] = 22
        // Array: [1, 4, 6, 8, 10, 45], Target: 22
        // Solution: 4 + 8 + 10 = 22 (indices 1, 3, 4)
        int[] nums2 = {1, 4, 6, 8, 10, 45};
        int target2 = 22;
        List<Integer> result2 = threeSum(nums2, target2);
        if (!result2.isEmpty()) {
            System.out.println("Test 2 - Optimal: " + result2);
            System.out.println("Values: " + nums2[result2.get(0)] + " + " + 
                             nums2[result2.get(1)] + " + " + nums2[result2.get(2)] + " = " + target2);
        }
        
        // Test Case 3: No solution exists
        // Array: [1, 2, 3], Target: 100 (impossible to achieve)
        int[] nums3 = {1, 2, 3};
        int target3 = 100;
        List<Integer> result3 = threeSum(nums3, target3);
        if (result3.isEmpty()) {
            System.out.println("Test 3 - No triplet found for target " + target3);
        }
    }
}