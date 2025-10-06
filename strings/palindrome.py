#  python implementation
#  Two-pointer approach - Most efficient
#  Time: O(n), Space: O(1) 

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
