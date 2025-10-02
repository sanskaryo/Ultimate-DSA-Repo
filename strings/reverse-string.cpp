#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

/**
 * String Reversal Techniques
 * 
 * This file demonstrates various approaches to reverse strings:
 * 1. Two-pointer technique
 * 2. Using stack
 * 3. Recursive approach
 * 4. STL reverse function
 * 5. In-place reversal for character arrays
 */

class StringReversal {
public:
    /**
     * Two-pointer approach - Most efficient
     * Time: O(n), Space: O(1)
     */
    static std::string reverseTwoPointer(std::string str) {
        int left = 0;
        int right = str.length() - 1;
        
        while (left < right) {
            std::swap(str[left], str[right]);
            left++;
            right--;
        }
        
        return str;
    }
    
    /**
     * Using stack - Good for understanding
     * Time: O(n), Space: O(n)
     */
    static std::string reverseUsingStack(const std::string& str) {
        std::stack<char> charStack;
        
        // Push all characters to stack
        for (char ch : str) {
            charStack.push(ch);
        }
        
        std::string reversed = "";
        
        // Pop all characters from stack
        while (!charStack.empty()) {
            reversed += charStack.top();
            charStack.pop();
        }
        
        return reversed;
    }
    
    /**
     * Recursive approach
     * Time: O(n), Space: O(n) due to recursion stack
     */
    static std::string reverseRecursive(const std::string& str) {
        if (str.length() <= 1) {
            return str;
        }
        
        return reverseRecursive(str.substr(1)) + str[0];
    }
    
    /**
     * Using STL reverse function
     * Time: O(n), Space: O(1)
     */
    static std::string reverseSTL(std::string str) {
        std::reverse(str.begin(), str.end());
        return str;
    }
    
    /**
     * In-place reversal for character arrays
     * Time: O(n), Space: O(1)
     */
    static void reverseCharArray(char arr[], int length) {
        int left = 0;
        int right = length - 1;
        
        while (left < right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    
    /**
     * Reverse words in a string
     * Example: "Hello World" -> "World Hello"
     * Time: O(n), Space: O(1)
     */
    static std::string reverseWords(std::string str) {
        // Remove extra spaces
        int write = 0;
        bool spaceFound = false;
        
        for (int read = 0; read < str.length(); read++) {
            if (str[read] != ' ') {
                if (spaceFound) {
                    str[write++] = ' ';
                    spaceFound = false;
                }
                str[write++] = str[read];
            } else {
                spaceFound = true;
            }
        }
        
        str.resize(write);
        
        // Reverse the entire string
        std::reverse(str.begin(), str.end());
        
        // Reverse each word
        int start = 0;
        for (int i = 0; i <= str.length(); ++i) {
            if (i == str.length() || str[i] == ' ') {
                std::reverse(str.begin() + start, str.begin() + i);
                start = i + 1;
            }
        }
        
        return str;
    }
    
    /**
     * Check if string is palindrome using reversal
     * Time: O(n), Space: O(n)
     */
    static bool isPalindromeUsingReverse(const std::string& str) {
        std::string cleaned = "";
        
        // Keep only alphanumeric characters and convert to lowercase
        for (char ch : str) {
            if (std::isalnum(ch)) {
                cleaned += std::tolower(ch);
            }
        }
        
        std::string reversed = reverseTwoPointer(cleaned);
        return cleaned == reversed;
    }
    
    /**
     * Optimized palindrome check without creating reversed string
     * Time: O(n), Space: O(1)
     */
    static bool isPalindromeOptimal(const std::string& str) {
        int left = 0;
        int right = str.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !std::isalnum(str[left])) {
                left++;
            }
            
            // Skip non-alphanumeric characters from right
            while (left < right && !std::isalnum(str[right])) {
                right--;
            }
            
            // Compare characters (case-insensitive)
            if (std::tolower(str[left]) != std::tolower(str[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};

// Test functions
void testReversal() {
    std::string test = "Hello World";
    
    std::cout << "Original: " << test << std::endl;
    std::cout << "Two-pointer: " << StringReversal::reverseTwoPointer(test) << std::endl;
    std::cout << "Stack: " << StringReversal::reverseUsingStack(test) << std::endl;
    std::cout << "Recursive: " << StringReversal::reverseRecursive(test) << std::endl;
    std::cout << "STL: " << StringReversal::reverseSTL(test) << std::endl;
    
    // Test character array reversal
    char charArray[] = "Programming";
    int length = sizeof(charArray) - 1; // Exclude null terminator
    std::cout << "Original char array: " << charArray << std::endl;
    StringReversal::reverseCharArray(charArray, length);
    std::cout << "Reversed char array: " << charArray << std::endl;
}

void testWordReversal() {
    std::vector<std::string> tests = {
        "Hello World",
        "  The   sky   is   blue  ",
        "a",
        ""
    };
    
    std::cout << "\n--- Word Reversal Tests ---" << std::endl;
    for (const std::string& test : tests) {
        std::cout << "Original: \"" << test << "\"" << std::endl;
        std::cout << "Reversed: \"" << StringReversal::reverseWords(test) << "\"" << std::endl;
        std::cout << std::endl;
    }
}

void testPalindrome() {
    std::vector<std::string> tests = {
        "A man a plan a canal Panama",
        "race a car",
        "Madam",
        "hello",
        "Was it a car or a cat I saw?"
    };
    
    std::cout << "\n--- Palindrome Tests ---" << std::endl;
    for (const std::string& test : tests) {
        bool result1 = StringReversal::isPalindromeUsingReverse(test);
        bool result2 = StringReversal::isPalindromeOptimal(test);
        
        std::cout << "\"" << test << "\" -> " 
                  << (result1 ? "Palindrome" : "Not Palindrome")
                  << " (Optimal: " << (result2 ? "Yes" : "No") << ")" << std::endl;
    }
}

int main() {
    testReversal();
    testWordReversal();
    testPalindrome();
    
    return 0;
}