/**
 * Intersection of Two Arrays
 * ==========================
 * 
 * Problem: Given two integer arrays, return an array of their intersection. 
 * Each element in the result must be unique and you may return the result in any order.
 * 
 * Approach 1 - Hash Set (Optimized):
 * - Convert first array to unordered_set for O(1) lookups
 * - Iterate through second array and check if each element exists in the set
 * - Add elements that exist in both arrays to result set
 * - Convert result set back to vector
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

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

class IntersectionSolver {
public:
    /**
     * Find intersection using hash set approach.
     * 
     * @param nums1 First vector of integers
     * @param nums2 Second vector of integers
     * @return Vector containing unique elements present in both arrays
     * 
     * Example:
     *   Input: nums1 = [1, 2, 2, 1], nums2 = [2, 2]
     *   Output: [2]
     */
    static std::vector<int> intersectionOptimized(const std::vector<int>& nums1, 
                                                  const std::vector<int>& nums2) {
        // Convert first array to set for O(1) lookups
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        
        // Set to store intersection results (automatically handles uniqueness)
        std::unordered_set<int> intersectionSet;
        
        // Check each element in second array
        for (int num : nums2) {
            // If element exists in first array, add to result
            if (set1.find(num) != set1.end()) {
                intersectionSet.insert(num);
            }
        }
        
        // Convert set back to vector
        return std::vector<int>(intersectionSet.begin(), intersectionSet.end());
    }
    
    /**
     * Find intersection using sorting + two pointers approach.
     * Time: O(n log n + m log m), Space: O(1) excluding result
     */
    static std::vector<int> intersectionSorting(std::vector<int> nums1, 
                                               std::vector<int> nums2) {
        // Sort both arrays
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        // Two pointers and result set
        int i = 0, j = 0;
        std::unordered_set<int> intersectionSet;
        
        // Use two pointers to find common elements
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // Found common element
                intersectionSet.insert(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return std::vector<int>(intersectionSet.begin(), intersectionSet.end());
    }
    
    /**
     * Find intersection using brute force approach.
     * Time: O(n * m), Space: O(min(n, m))
     * Helps understand the problem better.
     */
    static std::vector<int> intersectionBruteForce(const std::vector<int>& nums1, 
                                                   const std::vector<int>& nums2) {
        std::unordered_set<int> intersectionSet;
        
        // Check each element in first array
        for (int num1 : nums1) {
            // Check if it exists in second array
            for (int num2 : nums2) {
                if (num1 == num2) {
                    intersectionSet.insert(num1);
                    break; // Found it, no need to check further
                }
            }
        }
        
        return std::vector<int>(intersectionSet.begin(), intersectionSet.end());
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
     * Sort vector for comparison (since order doesn't matter in intersection)
     */
    static std::vector<int> sortVector(std::vector<int> vec) {
        std::sort(vec.begin(), vec.end());
        return vec;
    }
    
    /**
     * Run comprehensive test cases for all approaches
     */
    static void runTestCases() {
        std::cout << "=== Intersection of Two Arrays Test Results ===\n\n";
        
        // Test cases with expected results
        std::vector<std::vector<int>> testCases1 = {
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
        
        std::vector<std::vector<int>> testCases2 = {
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
        
        std::vector<std::vector<int>> expectedResults = {
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
        
        std::vector<std::string> descriptions = {
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
        
        for (int i = 0; i < testCases1.size(); i++) {
            const auto& nums1 = testCases1[i];
            const auto& nums2 = testCases2[i];
            auto expected = sortVector(expectedResults[i]);
            
            std::cout << "Test Case " << (i + 1) << ": " << descriptions[i] << "\n";
            std::cout << "Input: nums1 = ";
            printVector(nums1);
            std::cout << ", nums2 = ";
            printVector(nums2);
            std::cout << "\nExpected: ";
            printVector(expected);
            std::cout << "\n";
            
            // Test all approaches
            auto resultOptimized = sortVector(intersectionOptimized(nums1, nums2));
            auto resultSorting = sortVector(intersectionSorting(nums1, nums2));
            auto resultBruteForce = sortVector(intersectionBruteForce(nums1, nums2));
            
            std::cout << "Hash Set Result: ";
            printVector(resultOptimized);
            std::cout << "\nSorting Result: ";
            printVector(resultSorting);
            std::cout << "\nBrute Force Result: ";
            printVector(resultBruteForce);
            std::cout << "\n";
            
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
    IntersectionSolver::runTestCases();
    
    // Interactive example
    std::cout << "\n=== Interactive Example ===\n";
    std::vector<int> nums1 = {1, 2, 2, 1, 3, 4};
    std::vector<int> nums2 = {2, 2, 3, 5, 6};
    std::cout << "Finding intersection of ";
    IntersectionSolver::printVector(nums1);
    std::cout << " and ";
    IntersectionSolver::printVector(nums2);
    std::cout << "\n";
    
    // Show step-by-step process for hash set approach
    std::cout << "\nStep-by-step process (Hash Set approach):\n";
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::cout << "Step 1: Convert nums1 to set: ";
    IntersectionSolver::printSet(set1);
    std::cout << "\n";
    
    std::unordered_set<int> intersectionSet;
    std::cout << "Step 2: Check each element in nums2:\n";
    
    for (int i = 0; i < nums2.size(); i++) {
        int num = nums2[i];
        std::cout << "  Check " << num << ": ";
        if (set1.find(num) != set1.end()) {
            intersectionSet.insert(num);
            std::cout << "✅ Found in nums1, added to result. Result so far: ";
            IntersectionSolver::printSet(intersectionSet);
            std::cout << "\n";
        } else {
            std::cout << "❌ Not in nums1, skipping.\n";
        }
    }
    
    std::vector<int> result(intersectionSet.begin(), intersectionSet.end());
    std::cout << "\nFinal intersection: ";
    IntersectionSolver::printVector(result);
    std::cout << "\n";
    
    // Performance comparison
    std::cout << "\n=== Performance Analysis ===\n";
    std::cout << "For arrays of size n and m:\n";
    std::cout << "• Hash Set:     O(n + m) time, O(min(n,m)) space - Best general approach\n";
    std::cout << "• Sorting:      O(n log n + m log m) time, O(1) space - Good for sorted data\n";
    std::cout << "• Brute Force:  O(n * m) time, O(min(n,m)) space - Only for small arrays\n";
    
    return 0;
}
