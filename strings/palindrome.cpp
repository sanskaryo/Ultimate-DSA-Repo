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