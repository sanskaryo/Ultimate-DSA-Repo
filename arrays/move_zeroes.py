"""
Move Zeroes
Given an array nums, move all 0's to the end while maintaining the relative order of the non-zero elements.

Approach:
- Use two pointers: one for iterating, one for placing non-zero elements.
- Fill the rest with zeroes.

Time Complexity: O(n)
Space Complexity: O(1)
"""

def move_zeroes(nums):
    insert_pos = 0
    for num in nums:
        if num != 0:
            nums[insert_pos] = num
            insert_pos += 1
    for i in range(insert_pos, len(nums)):
        nums[i] = 0
    return nums

# Test cases
if __name__ == "__main__":
    print(move_zeroes([0,1,0,3,12]))    # [1,3,12,0,0]
    print(move_zeroes([0,0,1]))        # [1,0,0]
    print(move_zeroes([1,2,3]))        # [1,2,3]
    print(move_zeroes([0,0,0]))        # [0,0,0]
    print(move_zeroes([4,0,5,0,6]))    # [4,5,6,0,0]
