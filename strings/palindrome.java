/**
 * java implementation
 * Two-pointer approach - Most efficient
 * Time: O(n), Space: O(1) 
*/

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
