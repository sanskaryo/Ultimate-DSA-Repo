#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * @brief Finds two numbers in a vector that add up to a target value.
 *
 * This optimal solution uses an std::unordered_map (hash map) to store numbers
 * we've seen and their indices. It iterates through the vector once,
 * achieving O(n) time complexity and O(n) space complexity.
 *
 * @param nums The input vector of integers.
 * @param target The target sum.
 * @return A vector of two indices, or an empty vector if no solution is found.
 */
std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    // Hash map to store {number, index}
    std::unordered_map<int, int> num_map;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        // Check if the complement exists in the map
        if (num_map.count(complement)) {
            // If it exists, we found the pair
            return {num_map[complement], i};
        }

        // Otherwise, insert the current number and its index into the map
        num_map[nums[i]] = i;
    }

    // Return an empty vector if no solution is found
    return {};
}

// --- Test Cases ---
int main() {
    // Input: nums = [2, 7, 11, 15], target = 9
    // Output: [0, 1]
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSum(nums1, target1);
    if (!result1.empty()) {
        std::cout << "[" << result1[0] << ", " << result1[1] << "]" << std::endl;
    }

    // Input: nums = [3, 2, 4], target = 6
    // Output: [1, 2]
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = twoSum(nums2, target2);
    if (!result2.empty()) {
        std::cout << "[" << result2[0] << ", " << result2[1] << "]" << std::endl;
    }

    return 0;
}



//o(n^2)
// #include <vector>

// std::vector<int> twoSumBruteForce(const std::vector<int>& nums, int target) {
//     int n = nums.size();
//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             if (nums[i] + nums[j] == target) {
//                 return {i, j};
//             }
//         }
//     }
//     return {};
// }