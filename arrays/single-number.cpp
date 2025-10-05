/**
 * Single Number
 * =============
 * 
 * Problem: Given a non-empty array of integers nums, every element appears twice 
 * except for one. Find that single one. You must implement a solution with a 
 * linear runtime complexity and use only constant extra space.
 * 
 * Approach 1 - XOR Bit Manipulation (Optimized):
 * - Use XOR operation: a ^ a = 0 and a ^ 0 = a
 * - XOR all elements together
 * - Duplicate numbers cancel out (become 0)
 * - Single number remains
 * 
 * Approach 2 - Hash Set:
 * - Use set to track seen numbers
 * - Add number if not seen, remove if already seen
 * - Remaining number is the single one
 * 
 * Time Complexity: O(n) for all approaches
 * Space Complexity: O(1) for XOR, O(n) for hash set
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class SingleNumberSolver {
public:
    
    /**
     * Find single number using XOR bit manipulation.
     * 
     * @param nums Vector of integers
     * @return The single number that appears only once
     * 
     * Example:
     *   Input: nums = [2, 2, 1]
     *   Output: 1
     *   
     *   Input: nums = [4, 1, 2, 1, 2]
     *   Output: 4
     */
    static int singleNumberOptimized(vector<int>& nums) {
        int result = 0;
        
        for (int num : nums) {
            result ^= num;
        }
        
        return result;
    }
    
    /**
     * Find single number using hash set.
     */
    static int singleNumberHashSet(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.count(num)) {
                seen.erase(num);
            } else {
                seen.insert(num);
            }
        }
        
        return *seen.begin();
    }
    
    /**
     * Find single number using mathematical approach.
     */
    static int singleNumberMath(vector<int>& nums) {
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        
        int sumUnique = 0;
        for (int num : uniqueNums) {
            sumUnique += num;
        }
        
        int sumAll = 0;
        for (int num : nums) {
            sumAll += num;
        }
        
        return 2 * sumUnique - sumAll;
    }
    
    static void printVector(const vector<int>& vec, const string& label = "") {
        if (!label.empty()) {
            cout << label << ": ";
        }
        cout << "[";
        for (size_t i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    static void runTestCases() {
        cout << "=== Single Number Test Results (C++) ===" << endl << endl;
        
        vector<pair<vector<int>, int>> testCases = {
            {{2, 2, 1}, 1},
            {{4, 1, 2, 1, 2}, 4},
            {{1}, 1},
            {{1, 3, 1, -1, 3}, -1},
            {{0, 1, 0}, 1},
            {{7, 3, 5, 3, 5}, 7},
            {{-1, -1, -2}, -2},
            {{100, 200, 100}, 200}
        };
        
        vector<string> descriptions = {
            "Basic case with three elements",
            "Multiple pairs with single number",
            "Single element array",
            "Negative number as single",
            "Zero in array",
            "Larger numbers",
            "All negative numbers",
            "Large value differences"
        };
        
        for (size_t i = 0; i < testCases.size(); i++) {
            cout << "Test Case " << (i + 1) << ": " << descriptions[i] << endl;
            
            vector<int> nums = testCases[i].first;
            int expected = testCases[i].second;
            
            printVector(nums, "Input   ");
            cout << "Expected: " << expected << endl;
            
            int resultXOR = singleNumberOptimized(nums);
            int resultSet = singleNumberHashSet(nums);
            int resultMath = singleNumberMath(nums);
            
            cout << "XOR Result:      " << resultXOR << endl;
            cout << "Hash Set Result: " << resultSet << endl;
            cout << "Math Result:     " << resultMath << endl;
            
            bool xorCorrect = (resultXOR == expected);
            bool setCorrect = (resultSet == expected);
            bool mathCorrect = (resultMath == expected);
            
            cout << "✅ XOR:      " << (xorCorrect ? "PASSED" : "FAILED") << endl;
            cout << "✅ Hash Set: " << (setCorrect ? "PASSED" : "FAILED") << endl;
            cout << "✅ Math:     " << (mathCorrect ? "PASSED" : "FAILED") << endl;
            cout << string(70, '-') << endl;
        }
    }
};

int main() {
    SingleNumberSolver::runTestCases();
    
    cout << "\n=== Interactive Example ===" << endl;
    vector<int> sampleNums = {4, 1, 2, 1, 2};
    cout << "Finding single number in: ";
    SingleNumberSolver::printVector(sampleNums);
    
    cout << "\nStep-by-step XOR process:" << endl;
    int result = 0;
    
    for (size_t i = 0; i < sampleNums.size(); i++) {
        int prevResult = result;
        result ^= sampleNums[i];
        cout << "Step " << (i + 1) << ": " << prevResult << " ^ " 
             << sampleNums[i] << " = " << result << endl;
    }
    
    cout << "\nFinal single number: " << result << endl;
    
    cout << "\n=== Performance Analysis ===" << endl;
    cout << "For an array of n elements:" << endl;
    cout << "• XOR Approach:      O(n) time, O(1) space - Optimal solution" << endl;
    cout << "• Hash Set Approach: O(n) time, O(n) space - Alternative" << endl;
    cout << "• Math Approach:     O(n) time, O(n) space - Mathematical" << endl;
    
    return 0;
}
