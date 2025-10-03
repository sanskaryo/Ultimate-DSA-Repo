/**
 * Two Sum Problem
 * ===============
 * 
 * Problem: Given an array of integers and a target sum, return indices of two numbers 
 * that add up to the target. Assume exactly one solution exists.
 * 
 * Approach 1 - Hash Map (Optimized):
 * - Use unordered_map to store numbers and their indices as we iterate
 * - For each number, check if (target - current_number) exists in map
 * - If found, return both indices
 * - If not found, add current number and index to map
 * 
 * Approach 2 - Brute Force:
 * - Try all possible pairs using nested loops
 * - Check if each pair sums to target
 * 
 * Time Complexity: O(n) for hash map, O(n²) for brute force
 * Space Complexity: O(n) for hash map, O(1) for brute force
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class TwoSumSolver {
public:
    /**
     * Find two numbers that add up to target using hash map approach.
     * 
     * @param nums Vector of integers
     * @param target Target sum we want to achieve
     * @return Vector containing indices of the two numbers that sum to target
     * 
     * Example:
     *   Input: nums = [2, 7, 11, 15], target = 9
     *   Output: [0, 1] (because nums[0] + nums[1] = 2 + 7 = 9)
     */
    static std::vector<int> twoSumOptimized(const std::vector<int>& nums, int target) {
        // Hash map to store number -> index mapping
        std::unordered_map<int, int> numToIndex;
        
        // Iterate through the array with index
        for (int currentIndex = 0; currentIndex < nums.size(); currentIndex++) {
            int currentNum = nums[currentIndex];
            
            // Calculate what number we need to reach the target
            int neededNum = target - currentNum;
            
            // Check if the needed number exists in our hash map
            auto it = numToIndex.find(neededNum);
            if (it != numToIndex.end()) {
                // Found the pair! Return indices
                return {it->second, currentIndex};
            }
            
            // Store current number and its index for future lookups
            numToIndex[currentNum] = currentIndex;
        }
        
        // This should never happen if problem guarantees a solution exists
        return {};
    }
    
    /**
     * Find two numbers that add up to target using brute force approach.
     * Time: O(n²), Space: O(1)
     * Useful for understanding the problem better.
     */
    static std::vector<int> twoSumBruteForce(const std::vector<int>& nums, int target) {
        int arrayLength = nums.size();
        
        // Try all possible pairs
        for (int firstIndex = 0; firstIndex < arrayLength - 1; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < arrayLength; secondIndex++) {
                // Check if current pair sums to target
                if (nums[firstIndex] + nums[secondIndex] == target) {
                    return {firstIndex, secondIndex};
                }
            }
        }
        
        // No solution found
        return {};
    }
    
    /**
     * Print vector in readable format
     */
    static void printVector(const std::vector<int>& vec) {
        std::cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i];
            if (i < vec.size() - 1) std::cout << ", ";
        }
        std::cout << "]";
    }
    
    /**
     * Verify if the result indices give the correct sum
     */
    static bool verifyResult(const std::vector<int>& nums, const std::vector<int>& result, int target) {
        if (result.size() != 2) return false;
        return nums[result[0]] + nums[result[1]] == target;
    }
    
    /**
     * Run comprehensive test cases for both approaches
     */
    static void runTestCases() {
        std::cout << "=== Two Sum Problem Test Results ===\n\n";
        
        // Test cases with expected results
        std::vector<std::vector<int>> testNums = {
            {2, 7, 11, 15},
            {3, 2, 4},
            {3, 3},
            {1, 5, 3, 8, 2},
            {-1, -2, -3, -4, -5}
        };
        
        std::vector<int> testTargets = {9, 6, 6, 10, -8};
        
        std::vector<std::vector<int>> expectedResults = {
            {0, 1},
            {1, 2},
            {0, 1},
            {1, 3},
            {2, 4}
        };
        
        std::vector<std::string> descriptions = {
            "Basic case - first two elements sum to target",
            "Target requires elements from middle and end",
            "Duplicate numbers that sum to target",
            "Array with multiple valid pairs",
            "Negative numbers case"
        };
        
        for (int i = 0; i < testNums.size(); i++) {
            const auto& nums = testNums[i];
            int target = testTargets[i];
            const auto& expected = expectedResults[i];
            
            std::cout << "Test Case " << (i + 1) << ": " << descriptions[i] << "\n";
            std::cout << "Input: nums = ";
            printVector(nums);
            std::cout << ", target = " << target << "\n";
            std::cout << "Expected: ";
            printVector(expected);
            std::cout << "\n";
            
            // Test optimized approach
            auto resultOptimized = twoSumOptimized(nums, target);
            std::cout << "Optimized Result: ";
            printVector(resultOptimized);
            std::cout << "\n";
            
            // Test brute force approach
            auto resultBruteForce = twoSumBruteForce(nums, target);
            std::cout << "Brute Force Result: ";
            printVector(resultBruteForce);
            std::cout << "\n";
            
            // Verify correctness
            bool optimizedCorrect = verifyResult(nums, resultOptimized, target);
            bool bruteForceCorrect = verifyResult(nums, resultBruteForce, target);
            
            std::cout << "✅ Optimized: " << (optimizedCorrect ? "PASSED" : "FAILED") << "\n";
            std::cout << "✅ Brute Force: " << (bruteForceCorrect ? "PASSED" : "FAILED") << "\n";
            std::cout << std::string(60, '-') << "\n";
        }
    }
};

/**
 * Main function to run all test cases and interactive example
 */
int main() {
    TwoSumSolver::runTestCases();
    
    // Interactive example
    std::cout << "\n=== Interactive Example ===\n";
    std::vector<int> sampleNums = {2, 7, 11, 15};
    int sampleTarget = 9;
    
    std::cout << "Finding two numbers in ";
    TwoSumSolver::printVector(sampleNums);
    std::cout << " that sum to " << sampleTarget << "\n";
    
    auto result = TwoSumSolver::twoSumOptimized(sampleNums, sampleTarget);
    
    if (!result.empty()) {
        std::cout << "Found at indices: ";
        TwoSumSolver::printVector(result);
        std::cout << "\n";
        std::cout << "Numbers: " << sampleNums[result[0]] << " + " 
                  << sampleNums[result[1]] << " = " << sampleTarget << "\n";
    } else {
        std::cout << "No solution found!\n";
    }
    
    return 0;
}
