

def binary_search(nums, target):
    """
    Perform binary search on a sorted list to find the index of the target.

    :param nums: List[int] - A sorted list of integers
    :param target: int - The number to search for
    :return: int - Index of target if found, otherwise -1
    """

    low = 0
    high = len(nums) - 1

    while low <= high:
        mid = low + (high - low) // 2  # Avoids potential overflow

        # Check if mid is the target
        if nums[mid] == target:
            return mid
        # If target is greater, ignore left half
        elif nums[mid] < target:
            low = mid + 1
        # If target is smaller, ignore right half
        else:
            high = mid - 1

    # Target not found
    return -1


