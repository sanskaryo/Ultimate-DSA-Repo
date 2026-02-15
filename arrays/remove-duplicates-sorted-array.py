"""
Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and return the new length.

Approach:
- Use two pointers: one for iterating, one for placing unique elements.
- Overwrite duplicates in-place.

Time Complexity: O(n)
Space Complexity: O(1)
"""

def remove_duplicates(nums):
    if not nums:
        return 0
    write_index = 1
    for i in range(1, len(nums)):
        if nums[i] != nums[i-1]:
            nums[write_index] = nums[i]
            write_index += 1
    return write_index

# Test cases
if __name__ == "__main__":
    arr = [1,1,2]
    print(remove_duplicates(arr), arr[:2])  # 2, [1,2]
    arr = [0,0,1,1,1,2,2,3,3,4]
    print(remove_duplicates(arr), arr[:5])  # 5, [0,1,2,3,4]
    arr = []
    print(remove_duplicates(arr), arr)      # 0, []
    arr = [1,2,3]
    print(remove_duplicates(arr), arr[:3])  # 3, [1,2,3]
    arr = [1,1,1,1]
    print(remove_duplicates(arr), arr[:1])  # 1, [1]
