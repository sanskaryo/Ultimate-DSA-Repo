/**
 * Contains Duplicate
 * ==================
 * 
 * Problem: Given an integer array, return true if any value appears at least twice 
 * in the array, and return false if every element is distinct.
 * 
 * Approach 1 - Hash Set (Optimized):
 * - Use unordered_set to store elements as we iterate
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

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

class ContainsDuplicateSolver {
public:
    /**
     * Check for duplicates using hash set approach.
     * 
     * @param nums Vector of integers
     * @return True if duplicates exist, false otherwise
     * 
     * Example:
     *   Input: nums = [1, 2, 3, 1]
     *   Output: true (1 appears twice)
     */
    static bool containsDuplicateOptimized(const std::vector<int>& nums) {
        // Hash set to store seen elements
        std::unordered_set<int> seenElements;
        
        // Check each element
        for (int num : nums) {
            // If element already exists in set, we found a duplicate
            if (seenElements.find(num) != seenElements.end()) {
                return true;
            }
            // Add current element to set
            seenElements.insert(num);
        }
        
        // No duplicates found
        return false;
    }
    
    /**
     * Check for duplicates using sorting approach.
     * Time: O(n log n), Space: O(1)
     */
    static bool containsDuplicateSorting(std::vector<int> nums) {
        if (nums.size() <= 1) {
            return false;
        }
        
        // Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Check adjacent elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
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
    static bool containsDuplicateBruteForce(const std::vector<int>& nums) {
        int arrayLength = nums.size();
        
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
    static int findFirstDuplicate(const std::vector<int>& nums) {
        std::unordered_set<int> seenElements;
        
        for (int num : nums) {
            if (seenElements.find(num) != seenElements.end()) {
                return num;
            }
            seenElements.insert(num);
        }
        
        return -1; // No duplicate found
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
     * Print set in readable format
     */
    static void printSet(const std::unordered_set<int>& s) {
        std::cout << "{";
        bool first = true;
        for (int elem : s) {
            if (!first) std::cout << ", ";
            std::cout << elem;
            first = false;
        }
        std::cout << "}";
    }
    
    /**
     * Run comprehensive test cases for all approaches
     */
    static void runTestCases() {
        std::cout << "=== Contains Duplicate Test Results ===\n\n";
        
        // Test cases with expected results
        std::vector<std::vector<int>> testCases = {
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
        
        std::vector<bool> expectedResults = {
            true, false, true, false, false, true, true, true, false
        };
        
        std::vector<std::string> descriptions = {
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
        
        for (int i = 0; i < testCases.size(); i++) {
            const auto& nums = testCases[i];
            bool expected = expectedResults[i];
            
            std::cout << "Test Case " << (i + 1) << ": " << descriptions[i] << "\n";
            std::cout << "Input: ";
            printVector(nums);
            std::cout << "\nExpected: " << (expected ? "true" : "false") << "\n";
            
            // Test all approaches
            bool resultOptimized = containsDuplicateOptimized(nums);
            bool resultSorting = containsDuplicateSorting(nums);
            bool resultBruteForce = containsDuplicateBruteForce(nums);
            
            std::cout << "Hash Set Result: " << (resultOptimized ? "true" : "false") << "\n";
            std::cout << "Sorting Result: " << (resultSorting ? "true" : "false") << "\n";
            std::cout << "Brute Force Result: " << (resultBruteForce ? "true" : "false") << "\n";
            
            // Find first duplicate if it exists
            if (expected) {
                int firstDuplicate = findFirstDuplicate(nums);
                std::cout << "First Duplicate Found: " << firstDuplicate << "\n";
            }
            
            // Verify correctness
            bool optimizedCorrect = resultOptimized == expected;
            bool sortingCorrect = resultSorting == expected;
            bool bruteForceCorrect = resultBruteForce == expected;
            
            std::cout << "✅ Hash Set: " << (optimizedCorrect ? "PASSED" : "FAILED") << "\n";
            std::cout << "✅ Sorting: " << (sortingCorrect ? "PASSED" : "FAILED") << "\n";
            std::cout << "✅ Brute Force: " << (bruteForceCorrect ? "PASSED" : "FAILED") << "\n";
            std::cout << std::string(70, '-') << "\n";
        }
    }
};

/**
 * Main function to run all test cases and interactive example
 */
int main() {
    ContainsDuplicateSolver::runTestCases();
    
    // Interactive example
    std::cout << "\n=== Interactive Example ===\n";
    std::vector<int> sampleNums = {1, 3, 2, 4, 3, 5};
    std::cout << "Checking array: ";
    ContainsDuplicateSolver::printVector(sampleNums);
    std::cout << "\n";
    
    // Show step-by-step process for hash set approach
    std::cout << "\nStep-by-step process (Hash Set approach):\n";
    std::unordered_set<int> seen;
    
    for (int i = 0; i < sampleNums.size(); i++) {
        int num = sampleNums[i];
        std::cout << "Step " << (i + 1) << ": Checking element " << num << "\n";
        
        if (seen.find(num) != seen.end()) {
            std::cout << "  ❌ Element " << num << " already seen! Duplicate found.\n";
            std::cout << "  Seen elements so far: ";
            ContainsDuplicateSolver::printSet(seen);
            std::cout << "\n";
            break;
        } else {
            seen.insert(num);
            std::cout << "  ✅ Element " << num << " is new. Adding to seen set.\n";
            std::cout << "  Seen elements so far: ";
            ContainsDuplicateSolver::printSet(seen);
            std::cout << "\n";
        }
    }
    
    // Performance comparison
    std::cout << "\n=== Performance Analysis ===\n";
    std::cout << "For an array of size n:\n";
    std::cout << "• Hash Set:    O(n) time, O(n) space - Best for most cases\n";
    std::cout << "• Sorting:     O(n log n) time, O(1) space - Good when space is limited\n";
    std::cout << "• Brute Force: O(n²) time, O(1) space - Only for very small arrays\n";
    
    return 0;
}
