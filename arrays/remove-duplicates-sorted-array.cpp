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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class RemoveDuplicatesSolver {
public:
    /**
     * Remove duplicates from sorted array using two-pointer approach.
     * 
     * @param nums Sorted vector of integers (modified in-place)
     * @return Length of array after removing duplicates
     * 
     * Example:
     *   Input: nums = [1, 1, 2]
     *   Output: 2, and nums = [1, 2, _]
     *   Explanation: First 2 elements are unique
     */
    static int removeDuplicatesOptimized(std::vector<int>& nums) {
        // Handle edge case - empty array
        if (nums.empty()) {
            return 0;
        }
        
        // Slow pointer - tracks position for next unique element
        int slowPointer = 0;
        
        // Fast pointer - scans through array starting from index 1
        for (int fastPointer = 1; fastPointer < nums.size(); fastPointer++) {
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
    static int removeDuplicatesBruteForce(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        // Track unique elements
        std::vector<int> uniqueElements;
        
        // Add first element (always unique in sorted array)
        uniqueElements.push_back(nums[0]);
        
        // Check each element against the last unique element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != uniqueElements.back()) {
                uniqueElements.push_back(nums[i]);
            }
        }
        
        // Copy unique elements back to original array
        for (int i = 0; i < uniqueElements.size(); i++) {
            nums[i] = uniqueElements[i];
        }
        
        return uniqueElements.size();
    }
    
    /**
     * Print array showing only the valid elements up to given length
     */
    static void printArrayWithLength(const std::vector<int>& nums, int length) {
        std::cout << "[";
        for (int i = 0; i < nums.size(); i++) {
            if (i < length) {
                std::cout << nums[i];
            } else {
                std::cout << "_";
            }
            if (i < nums.size() - 1) std::cout << ", ";
        }
        std::cout << "]";
    }
    
    /**
     * Print regular vector
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
     * Verify if result is correct
     */
    static bool verifyResult(const std::vector<int>& nums, int resultLength, 
                           const std::vector<int>& expected, int expectedLength) {
        if (resultLength != expectedLength) return false;
        for (int i = 0; i < expectedLength; i++) {
            if (nums[i] != expected[i]) return false;
        }
        return true;
    }
    
    /**
     * Run comprehensive test cases for both approaches
     */
    static void runTestCases() {
        std::cout << "=== Remove Duplicates from Sorted Array Test Results ===\n\n";
        
        // Test cases with expected results
        std::vector<std::vector<int>> testCases = {
            {1, 1, 2},
            {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
            {1, 2, 3, 4, 5},
            {1},
            {2, 2, 2, 2},
            {}
        };
        
        std::vector<int> expectedLengths = {2, 5, 5, 1, 1, 0};
        
        std::vector<std::vector<int>> expectedUnique = {
            {1, 2},
            {0, 1, 2, 3, 4},
            {1, 2, 3, 4, 5},
            {1},
            {2},
            {}
        };
        
        std::vector<std::string> descriptions = {
            "Basic case with some duplicates",
            "Multiple consecutive duplicates",
            "No duplicates present",
            "Single element array",
            "All elements are same",
            "Empty array edge case"
        };
        
        for (int i = 0; i < testCases.size(); i++) {
            auto originalNums = testCases[i];
            int expectedLength = expectedLengths[i];
            auto expectedUniqueElements = expectedUnique[i];
            
            std::cout << "Test Case " << (i + 1) << ": " << descriptions[i] << "\n";
            std::cout << "Input: ";
            printVector(originalNums);
            std::cout << "\n";
            std::cout << "Expected Length: " << expectedLength << "\n";
            std::cout << "Expected Unique Elements: ";
            printVector(expectedUniqueElements);
            std::cout << "\n";
            
            // Test optimized approach
            auto numsOptimized = originalNums;
            int resultLengthOptimized = removeDuplicatesOptimized(numsOptimized);
            
            std::cout << "Optimized Result Length: " << resultLengthOptimized << "\n";
            std::cout << "Optimized Result Array: ";
            printArrayWithLength(numsOptimized, resultLengthOptimized);
            std::cout << "\n";
            
            // Test brute force approach
            auto numsBruteForce = originalNums;
            int resultLengthBruteForce = removeDuplicatesBruteForce(numsBruteForce);
            
            std::cout << "Brute Force Result Length: " << resultLengthBruteForce << "\n";
            std::cout << "Brute Force Result Array: ";
            printArrayWithLength(numsBruteForce, resultLengthBruteForce);
            std::cout << "\n";
            
            // Verify correctness
            bool optimizedCorrect = verifyResult(numsOptimized, resultLengthOptimized, 
                                               expectedUniqueElements, expectedLength);
            bool bruteForceCorrect = verifyResult(numsBruteForce, resultLengthBruteForce, 
                                                expectedUniqueElements, expectedLength);
            
            std::cout << "✅ Optimized: " << (optimizedCorrect ? "PASSED" : "FAILED") << "\n";
            std::cout << "✅ Brute Force: " << (bruteForceCorrect ? "PASSED" : "FAILED") << "\n";
            std::cout << std::string(70, '-') << "\n";
        }
    }
};

/**
 * Main function to run all test cases and interactive example
 */
int main() {
    RemoveDuplicatesSolver::runTestCases();
    
    // Interactive example
    std::cout << "\n=== Interactive Example ===\n";
    std::vector<int> sampleNums = {1, 1, 2, 2, 3, 4, 4, 5};
    std::cout << "Original array: ";
    RemoveDuplicatesSolver::printVector(sampleNums);
    std::cout << "\n";
    
    // Show step-by-step process
    std::cout << "\nStep-by-step process:\n";
    auto numsCopy = sampleNums;
    int slow = 0;
    std::cout << "Initial: slow=0, array=";
    RemoveDuplicatesSolver::printVector(numsCopy);
    std::cout << "\n";
    
    for (int fast = 1; fast < numsCopy.size(); fast++) {
        if (numsCopy[fast] != numsCopy[slow]) {
            slow++;
            numsCopy[slow] = numsCopy[fast];
            std::cout << "Found unique " << numsCopy[fast] << ": slow=" << slow << ", array=";
            RemoveDuplicatesSolver::printVector(numsCopy);
            std::cout << "\n";
        }
    }
    
    int newLength = slow + 1;
    std::cout << "\nFinal result:\n";
    std::cout << "New length: " << newLength << "\n";
    std::cout << "Array after removing duplicates: ";
    RemoveDuplicatesSolver::printArrayWithLength(numsCopy, newLength);
    std::cout << "\n";
    
    return 0;
}
