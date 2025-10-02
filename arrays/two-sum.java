import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

public class TwoSum {

    /**
     * Finds two numbers in an array that add up to a target value.
     *
     * This optimal solution uses a HashMap to store numbers we've seen and their indices.
     * It iterates through the array once, achieving O(n) time complexity.
     *
     * @param nums The input array of integers.
     * @param target The target sum.
     * @return An array of two indices, or an exception if no solution is found.
     */
    public int[] findTwoSum(int[] nums, int target) {
        // Hash map to store <Number, Index>
        Map<Integer, Integer> numMap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];

            // If the map contains the complement, we have our solution
            if (numMap.containsKey(complement)) {
                return new int[]{numMap.get(complement), i};
            }

            // Otherwise, put the current number and its index into the map
            numMap.put(nums[i], i);
        }

        // If no solution is found, throw an exception
        throw new IllegalArgumentException("No two sum solution");
    }

    // --- Test Cases ---
    public static void main(String[] args) {
        TwoSum solution = new TwoSum();

        // Input: nums = [2, 7, 11, 15], target = 9
        // Output: [0, 1]
        int[] nums1 = {2, 7, 11, 15};
        int target1 = 9;
        int[] result1 = solution.findTwoSum(nums1, target1);
        System.out.println(Arrays.toString(result1));

        // Input: nums = [3, 2, 4], target = 6
        // Output: [1, 2]
        int[] nums2 = {3, 2, 4};
        int target2 = 6;
        int[] result2 = solution.findTwoSum(nums2, target2);
        System.out.println(Arrays.toString(result2));
    }
}




//o(n^2)
// public class TwoSumBruteForce {
//     public int[] findTwoSum(int[] nums, int target) {
//         int n = nums.length;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return new int[]{i, j};
//                 }
//             }
//         }
//         throw new IllegalArgumentException("No two sum solution");
//     }
// }