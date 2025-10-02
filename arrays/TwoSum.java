import java.util.HashMap;
import java.util.Map;

/**
 * Two Sum Problem
 * 
 * Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
public class TwoSum {
    
    /**
     * Finds two numbers in the array that add up to the target sum
     * @param nums array of integers
     * @param target target sum
     * @return array containing indices of the two numbers
     */
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numToIndex = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            
            if (numToIndex.containsKey(complement)) {
                return new int[]{numToIndex.get(complement), i};
            }
            
            numToIndex.put(nums[i], i);
        }
        
        // No solution found
        throw new IllegalArgumentException("No two sum solution");
    }
    
    /**
     * Brute force approach - O(n²) time complexity
     * @param nums array of integers
     * @param target target sum
     * @return array containing indices of the two numbers
     */
    public int[] twoSumBruteForce(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
    
    // Test the solution
    public static void main(String[] args) {
        TwoSum solution = new TwoSum();
        
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        
        int[] result = solution.twoSum(nums, target);
        System.out.println("Indices: [" + result[0] + ", " + result[1] + "]");
        System.out.println("Values: [" + nums[result[0]] + ", " + nums[result[1]] + "]");
    }
}