#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * @brief Brute Force Approach (O(n^3))
 * 
 * Simply check all possible triplets.
 * 
 * Time Complexity: O(n^3)
 * Space Complexity: O(1)
 */
vector<int> threeSumBruteForce(const vector<int>& nums, int target) {
    int n = nums.size();
    
    // Need at least 3 elements
    if (n < 3) {
        cout << "Array size of at least 3 is required to find a triplet."<< "\n";
        return {};
    }

    // Try all possible combinations of three different indices
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {            // j starts after i to avoid duplicates
            for (int k = j + 1; k < n; ++k) {        // k starts after j to avoid duplicates
                // Check if current triplet sums to target
                if (nums[i] + nums[j] + nums[k] == target) {
                    return {i, j, k};                 // Return indices of the triplet
                }
            }
        }
    }
    return {};  // No triplet found
}


/**
 * @brief Optimal Hash Map Approach (O(n^2))
 * 
 * For each element, reduce the problem to a Two Sum (target - nums[i]).
 * Use an unordered_map to store complements.
 * 
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */
vector<int> threeSum(const vector<int>& nums, int target) {
    int n = nums.size();

        // Need at least 3 elements
    if (n < 3) {
        cout << "Array size of at least 3 is required to find a triplet."<< "\n";
        return {};
    }

    // Fix the first element and solve Two Sum for the remaining elements
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> seen; // Maps value to its index
        int newTarget = target - nums[i];   // What the other two numbers should sum to
        
        // Look for two numbers that sum to newTarget in the remaining array
        for (int j = i + 1; j < n; ++j) {
            int complement = newTarget - nums[j];  // What we need to complete the triplet
            
            // Check if we've seen the complement before
            if (seen.count(complement)) {
                // Found triplet: nums[i] + nums[seen[complement]] + nums[j] = target
                return {i, seen[complement], j};
            }
            
            // Store current number and its index for future lookups
            seen[nums[j]] = j;
        }
    }

    return {};  // No triplet found
}


// --- Test Cases ---
int main() {
    // Test Case 1: Basic positive numbers with valid triplet
    // Expected: indices where nums[i] + nums[j] + nums[k] = 20
    // Array: [2, 7, 11, 15, -2], Target: 20
    // Solution: 2 + 7 + 11 = 20 (indices 0, 1, 2)
    vector<int> nums1 = {2, 7, 11, 15, -2};
    int target1 = 20;
    auto result1 = threeSum(nums1, target1);
    if (!result1.empty()) {
        cout << "Test 1 - Optimal: [" << result1[0] << ", " << result1[1] << ", " << result1[2] << "]\n";
        cout << "Values: " << nums1[result1[0]] << " + " << nums1[result1[1]] << " + " << nums1[result1[2]] << " = " << target1 << "\n";
    }

    auto brute1 = threeSumBruteForce(nums1, target1);
    if (!brute1.empty()) {
        cout << "Test 1 - Brute: [" << brute1[0] << ", " << brute1[1] << ", " << brute1[2] << "]\n";
    }

    // Test Case 2: Another set with valid triplet
    // Expected: indices where nums[i] + nums[j] + nums[k] = 22
    // Array: [1, 4, 6, 8, 10, 45], Target: 22
    // Solution: 4 + 8 + 10 = 22 (indices 1, 3, 4)
    vector<int> nums2 = {1, 4, 6, 8, 10, 45};
    int target2 = 22;
    auto result2 = threeSum(nums2, target2);
    if (!result2.empty()) {
        cout << "Test 2 - Optimal: [" << result2[0] << ", " << result2[1] << ", " << result2[2] << "]\n";
        cout << "Values: " << nums2[result2[0]] << " + " << nums2[result2[1]] << " + " << nums2[result2[2]] << " = " << target2 << "\n";
    }

    // Test Case 3: No solution exists
    // Array: [1, 2, 3], Target: 100 (impossible to achieve)
    vector<int> nums3 = {1, 2, 3};
    int target3 = 100;
    auto result3 = threeSum(nums3, target3);
    if (result3.empty()) {
        cout << "Test 3 - No triplet found for target " << target3 << "\n";
    }

    return 0;
}