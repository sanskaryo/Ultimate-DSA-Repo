/**
 * Plus One
 * ========
 * 
 * Problem: Given a large integer represented as an integer array digits, where each 
 * digits[i] is the ith digit of the integer. The digits are ordered from most 
 * significant to least significant in left-to-right order. Increment the large 
 * integer by one and return the resulting array of digits.
 * 
 * Approach 1 - Reverse Iteration with Carry (Optimized):
 * - Start from the last digit (least significant)
 * - Add 1 to the last digit
 * - Handle carry propagation: if digit becomes 10, set it to 0 and carry 1
 * - Continue until no carry or we've processed all digits
 * - If carry remains after processing all digits, insert 1 at the beginning
 * 
 * Approach 2 - Explicit Carry:
 * - Use carry variable to track overflow
 * - Process digits from right to left
 * - More verbose but easier to understand
 * 
 * Time Complexity: O(n) where n is the number of digits
 * Space Complexity: O(1) for in-place, O(n) if all digits are 9
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

class PlusOneSolver {
public:
    
    /**
     * Add one to the number using optimized carry propagation.
     * 
     * @param digits Vector of integers representing a large number
     * @return Vector of integers representing the incremented number
     * 
     * Example:
     *   Input: digits = [1, 2, 3]
     *   Output: [1, 2, 4]
     *   
     *   Input: digits = [9, 9, 9]
     *   Output: [1, 0, 0, 0]
     */
    static vector<int> plusOneOptimized(vector<int> digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            digits[i] = 0;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
    
    /**
     * Add one using explicit carry variable.
     * More verbose but easier to understand.
     */
    static vector<int> plusOneWithCarry(vector<int> digits) {
        int carry = 1;
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            int total = digits[i] + carry;
            digits[i] = total % 10;
            carry = total / 10;
            
            if (carry == 0) {
                break;
            }
        }
        
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
    
    /**
     * Recursive approach for educational purposes.
     */
    static vector<int> plusOneRecursive(vector<int> digits, int index = -1) {
        if (index == -1) {
            index = digits.size() - 1;
        }
        
        if (index < 0) {
            digits.insert(digits.begin(), 1);
            return digits;
        }
        
        if (digits[index] < 9) {
            digits[index]++;
            return digits;
        }
        
        digits[index] = 0;
        return plusOneRecursive(digits, index - 1);
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
    
    static bool vectorsEqual(const vector<int>& v1, const vector<int>& v2) {
        return v1 == v2;
    }
    
    static void runTestCases() {
        cout << "=== Plus One Test Results (C++) ===" << endl << endl;
        
        vector<pair<vector<int>, vector<int>>> testCases = {
            {{1, 2, 3}, {1, 2, 4}},
            {{4, 3, 2, 1}, {4, 3, 2, 2}},
            {{9}, {1, 0}},
            {{9, 9, 9}, {1, 0, 0, 0}},
            {{1, 9, 9}, {2, 0, 0}},
            {{0}, {1}},
            {{8, 9, 9, 9}, {9, 0, 0, 0}},
            {{1, 2, 9}, {1, 3, 0}}
        };
        
        vector<string> descriptions = {
            "Basic increment without carry",
            "Increment without carry propagation",
            "Single digit 9 (edge case)",
            "All digits are 9 (maximum carry)",
            "Partial 9s requiring carry",
            "Edge case: incrementing zero",
            "Multiple 9s at the end",
            "Single 9 at the end"
        };
        
        for (size_t i = 0; i < testCases.size(); i++) {
            cout << "Test Case " << (i + 1) << ": " << descriptions[i] << endl;
            
            vector<int> input = testCases[i].first;
            vector<int> expected = testCases[i].second;
            
            printVector(input, "Input   ");
            printVector(expected, "Expected");
            
            vector<int> resultOptimized = input;
            resultOptimized = plusOneOptimized(resultOptimized);
            
            vector<int> resultCarry = plusOneWithCarry(input);
            vector<int> resultRecursive = plusOneRecursive(input);
            
            printVector(resultOptimized, "Optimized ");
            printVector(resultCarry, "Carry     ");
            printVector(resultRecursive, "Recursive ");
            
            bool optimizedCorrect = vectorsEqual(resultOptimized, expected);
            bool carryCorrect = vectorsEqual(resultCarry, expected);
            bool recursiveCorrect = vectorsEqual(resultRecursive, expected);
            
            cout << "✅ Optimized:  " << (optimizedCorrect ? "PASSED" : "FAILED") << endl;
            cout << "✅ Carry:      " << (carryCorrect ? "PASSED" : "FAILED") << endl;
            cout << "✅ Recursive:  " << (recursiveCorrect ? "PASSED" : "FAILED") << endl;
            cout << string(70, '-') << endl;
        }
    }
};

int main() {
    PlusOneSolver::runTestCases();
    
    cout << "\n=== Interactive Example ===" << endl;
    vector<int> sampleDigits = {1, 9, 9};
    cout << "Adding 1 to number represented by: ";
    PlusOneSolver::printVector(sampleDigits);
    
    cout << "\nStep-by-step process (Optimized approach):" << endl;
    vector<int> digits = sampleDigits;
    int n = digits.size();
    
    for (int i = n - 1; i >= 0; i--) {
        cout << "\nStep " << (n - i) << ": Checking digit at index " << i 
             << " (value: " << digits[i] << ")" << endl;
        
        if (digits[i] < 9) {
            cout << "  ✅ Digit " << digits[i] << " < 9, increment it to " 
                 << (digits[i] + 1) << endl;
            digits[i]++;
            cout << "  Final result: ";
            PlusOneSolver::printVector(digits);
            break;
        } else {
            cout << "  ⚠️  Digit is 9, set to 0 and carry over" << endl;
            digits[i] = 0;
            cout << "  Current state: ";
            PlusOneSolver::printVector(digits);
            cout << " (carry continues)" << endl;
        }
    }
    
    cout << "\n=== Performance Analysis ===" << endl;
    cout << "For an array of n digits:" << endl;
    cout << "• Optimized Approach:  O(n) time, O(1) space* - Best for most cases" << endl;
    cout << "• Carry Approach:      O(n) time, O(n) space - More explicit" << endl;
    cout << "• Recursive Approach:  O(n) time, O(n) space - Educational" << endl;
    cout << "\n*O(1) when modifying in-place, O(n) when all digits are 9" << endl;
    
    return 0;
}
