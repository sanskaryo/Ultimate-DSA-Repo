/**
 * Move Zeroes
 * ===========
 * 
 * Problem: Given an integer array, move all 0's to the end while maintaining 
 * the relative order of non-zero elements. Must do this in-place.
 * 
 * Approach 1 - Two Pointers (Optimized):
 * - Use slow pointer to track position for next non-zero element
 * - Use fast pointer to scan through array
 * - When fast pointer finds non-zero element, place it at slow pointer position
 * - After placing all non-zeros, fill remaining positions with zeros
 * 
 * Approach 2 - Brute Force:
 * - Use additional vector to store non-zero elements
 * - Copy non-zeros first, then fill remaining with zeros
 * - Copy back to original array
 * 
 * Time Complexity: O(n) for both approaches
 * Space Complexity: O(1) for two pointers, O(n) for brute force
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class MoveZeroesSolver {
public:
    /**
     * Move all zeroes to end using two-pointer approach (in-place).
     * 
     * @param nums Vector of integers (modified in-place)
     * 
     * Example:
     *   Input: nums = [0, 1, 0, 3, 12]
     *   Output: nums = [1, 3, 12, 0, 0]
     *   Explanation: Non-zeros maintain relative order, zeros moved to end
     */
    static void moveZeroesOptimized(std::vector<int>& nums) {
        // Handle edge case - empty array or single element
        if (nums.size() <= 1) {
            return;
        }
        
        // Slow pointer - tracks position for next non-zero element
        int slowPointer = 0;
        
        // Fast pointer - scans through array to find non-zero elements
        for (int fastPointer = 0; fastPointer < nums.size(); fastPointer++) {
            // If current element is non-zero
            if (nums[fastPointer] != 0) {
                // Place non-zero element at slow pointer position
                nums[slowPointer] = nums[fastPointer];
                // Move slow pointer to next position
                slowPointer++;
            }
        }
        
        // Fill remaining positions with zeros
        for (int i = slowPointer; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
    
    /**
     * Alternative optimized approach using swapping.
     * Maintains relative order and minimizes writes.
     */
    static void moveZeroesSwapOptimized(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        
        // Position for next non-zero element
        int nonZeroPos = 0;
        
        // Move all non-zero elements to front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Swap only if positions are different
                if (i != nonZeroPos) {
                    std::swap(nums[nonZeroPos], nums[i]);
                }
                nonZeroPos++;
            }
        }
    }
    
    /**
     * Move zeroes using additional space for comparison.
     * Time: O(n), Space: O(n)
     * Helps understand the problem better.
     */
    static void moveZeroesBruteForce(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        
        // Store non-zero elements
        std::vector<int> nonZeroElements;
        int zeroCount = 0;
        
        // Separate non-zeros and count zeros
        for (int num : nums) {
            if (num != 0) {
                nonZeroElements.push_back(num);
            } else {
                zeroCount++;
            }
        }
        
        // Fill array: non-zeros first, then zeros
        for (int i = 0; i < nonZeroElements.size(); i++) {
            nums[i] = nonZeroElements[i];
        }
        
        for (int i = nonZeroElements.size(); i < nums.size(); i++) {
            nums[i] = 0;
        }
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
     * Print before and after arrays to show the transformation
     */
    static void printArrayChanges(const std::vector<int>& original, 
                                 const std::vector<int>& result, 
                                 const std::string& method) {
        std::cout << method << ":\n";
        std::cout << "  Before: ";
        printVector(original);
        std::cout << "\n  After:  ";
        printVector(result);
        std::cout << "\n";
    }
    
    /**
     * Verify if the result matches expected output
     */
    static bool verifyResult(const std::vector<int>& nums, const std::vector<int>& expected) {
        return nums == expected;
    }
    
    /**
     * Run comprehensive test cases for all approaches
     */
    static void runTestCases() {
        std::cout << "=== Move Zeroes Test Results ===\n\n";
        
        // Test cases with expected results
        std::vector<std::vector<int>> testCases = {
            {0, 1, 0, 3, 12},
            {0, 0, 1},
            {1, 0, 0},
            {0, 0, 0},
            {1, 2, 3},
            {0},
            {5},
            {0, 1},
            {1, 0}
        };
        
        std::vector<std::vector<int>> expectedResults = {
            {1, 3, 12, 0, 0},
            {1, 0, 0},
            {1, 0, 0},
            {0, 0, 0},
            {1, 2, 3},
            {0},
            {5},
            {1, 0},
            {1, 0}
        };
        
        std::vector<std::string> descriptions = {
            "Mixed zeros and non-zeros",
            "Leading zeros case",
            "Trailing zeros case",
            "All zeros case",
            "No zeros present",
            "Single zero element",
            "Single non-zero element",
            "Two elements - zero first",
            "Two elements - zero last"
        };
        
        for (int i = 0; i < testCases.size(); i++) {
            auto originalNums = testCases[i];
            auto expected = expectedResults[i];
            
            std::cout << "Test Case " << (i + 1) << ": " << descriptions[i] << "\n";
            std::cout << "Input: ";
            printVector(originalNums);
            std::cout << "\nExpected: ";
            printVector(expected);
            std::cout << "\n";
            
            // Test optimized approach
            auto numsOptimized = originalNums;
            moveZeroesOptimized(numsOptimized);
            printArrayChanges(originalNums, numsOptimized, "Optimized (Two Pointers)");
            
            // Test swap approach
            auto numsSwap = originalNums;
            moveZeroesSwapOptimized(numsSwap);
            printArrayChanges(originalNums, numsSwap, "Optimized (Swapping)");
            
            // Test brute force approach
            auto numsBruteForce = originalNums;
            moveZeroesBruteForce(numsBruteForce);
            printArrayChanges(originalNums, numsBruteForce, "Brute Force");
            
            // Verify correctness
            bool optimizedCorrect = verifyResult(numsOptimized, expected);
            bool swapCorrect = verifyResult(numsSwap, expected);
            bool bruteForceCorrect = verifyResult(numsBruteForce, expected);
            
            std::cout << "✅ Two Pointers: " << (optimizedCorrect ? "PASSED" : "FAILED") << "\n";
            std::cout << "✅ Swapping: " << (swapCorrect ? "PASSED" : "FAILED") << "\n";
            std::cout << "✅ Brute Force: " << (bruteForceCorrect ? "PASSED" : "FAILED") << "\n";
            std::cout << std::string(70, '-') << "\n";
        }
    }
};

/**
 * Main function to run all test cases and interactive example
 */
int main() {
    MoveZeroesSolver::runTestCases();
    
    // Interactive example
    std::cout << "\n=== Interactive Example ===\n";
    std::vector<int> sampleNums = {0, 1, 0, 3, 12, 0, 5};
    std::cout << "Original array: ";
    MoveZeroesSolver::printVector(sampleNums);
    std::cout << "\n";
    
    // Show step-by-step process for two-pointer approach
    std::cout << "\nStep-by-step process (Two Pointers):\n";
    auto numsCopy = sampleNums;
    int slow = 0;
    std::cout << "Initial: slow=0, array=";
    MoveZeroesSolver::printVector(numsCopy);
    std::cout << "\n";
    
    // Phase 1: Move non-zeros to front
    for (int fast = 0; fast < numsCopy.size(); fast++) {
        if (numsCopy[fast] != 0) {
            numsCopy[slow] = numsCopy[fast];
            slow++;
            std::cout << "Found non-zero " << numsCopy[fast] << ": slow=" << slow << ", array=";
            MoveZeroesSolver::printVector(numsCopy);
            std::cout << "\n";
        }
    }
    
    // Phase 2: Fill remaining with zeros
    int originalSlow = slow;
    for (int i = slow; i < numsCopy.size(); i++) {
        numsCopy[i] = 0;
    }
    
    std::cout << "\nAfter filling remaining " << (numsCopy.size() - originalSlow) 
              << " positions with zeros:\n";
    std::cout << "Final result: ";
    MoveZeroesSolver::printVector(numsCopy);
    std::cout << "\n";
    
    return 0;
}
