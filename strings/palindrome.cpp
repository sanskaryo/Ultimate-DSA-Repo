/**
 * c++ implementation
 * Two-pointer approach - Most efficient
 * Time: O(n), Space: O(1) 
*/
#include <iostream>
#include <string>
#include <cctype>  // for tolower and isspace
using namespace std;

bool isPalindrome(const string& str) {
    int left = 0, right = str.length() - 1; // intial variable setup

    while (left < right) {
        // Skip spaces from the left
        while (left < right && isspace(str[left])) left++;
        // Skip spaces from the right
        while (left < right && isspace(str[right])) right--;

        // Case insensitivity check
        if (tolower(str[left]) != tolower(str[right]))
            return false;

        left++;
        right--;
    }
    return true;
}

// array based setup for tests

int main() {
    string tests[] = {
        "racecar",
        "Ra ce car",
        "hello",
        "A man a plan a canal Panama",
        "No lemon, no melon",
        "",        // empty string
        " ",       // single space
        "  A  ",   // spaces around single char
        "Madam"
    };

    for (const auto& test : tests) {
        cout << (isPalindrome(test) ? "true" : "false") << endl; // ternery condition check for output in boolean exp
    }
    return 0;
}


// Python implementation of same code


def is_palindrome(str_):
    left, right = 0, len(str_) - 1  # initial variable setup

    while left < right:
        # Skip spaces from the left
        while left < right and str_[left].isspace():
            left += 1
        # Skip spaces from the right
        while left < right and str_[right].isspace():
            right -= 1

        # Case insensitivity check
        if str_[left].lower() != str_[right].lower():
            return False

        left += 1
        right -= 1

    return True


# Array based setup for tests
tests = [
    "racecar",
    "Ra ce car",
    "hello",
    "A man a plan a canal Panama",
    "No lemon, no melon",
    "",        # empty string
    " ",       # single space
    "  A  ",   # spaces around single char
    "Madam"
]

# Output
for test in tests:
    print("true" if is_palindrome(test) else "false")  # ternary condition check for output in boolean exp


//  Java implementation

public class PalindromeChecker {

    public static boolean isPalindrome(String str) {
        int left = 0, right = str.length() - 1; // initial variable setup

        while (left < right) {
            // Skip spaces from the left
            while (left < right && Character.isWhitespace(str.charAt(left))) left++;
            // Skip spaces from the right
            while (left < right && Character.isWhitespace(str.charAt(right))) right--;

            // Case insensitivity check
            if (Character.toLowerCase(str.charAt(left)) != Character.toLowerCase(str.charAt(right)))
                return false;

            left++;
            right--;
        }

        return true;
    }

    public static void main(String[] args) {
        // Array based setup for tests
        String[] tests = {
            "racecar",
            "Ra ce car",
            "hello",
            "A man a plan a canal Panama",
            "No lemon, no melon",
            "",        // empty string
            " ",       // single space
            "  A  ",   // spaces around single char
            "Madam"
        };

        for (String test : tests) {
            System.out.println(isPalindrome(test) ? "true" : "false"); // ternary condition check for output in boolean exp
        }
    }
}
