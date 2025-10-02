#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

/**
 * Maximum Subarray Problem Solutions
 * 
 * This file contains multiple approaches to solve the maximum subarray problem:
 * 1. Kadane's Algorithm (O(n))
 * 2. Divide and Conquer (O(n log n))
 * 3. Brute Force (O(n²))
 * 4. Prefix Sum approach
 */

class MaxSubarray {
public:
    /**
     * Kadane's Algorithm - Most efficient approach
     * Time: O(n), Space: O(1)
     */
    static int kadane(const std::vector<int>& arr) {
        if (arr.empty()) return 0;
        
        int maxCurrent = arr[0];
        int maxGlobal = arr[0];
        
        for (size_t i = 1; i < arr.size(); i++) {
            maxCurrent = std::max(arr[i], maxCurrent + arr[i]);
            maxGlobal = std::max(maxGlobal, maxCurrent);
        }
        
        return maxGlobal;
    }
    
    /**
     * Kadane's with subarray indices
     * Returns {maxSum, startIndex, endIndex}
     */
    static std::tuple<int, int, int> kadaneWithIndices(const std::vector<int>& arr) {
        if (arr.empty()) return {0, -1, -1};
        
        int maxSum = INT_MIN;
        int currentSum = 0;
        int start = 0, end = 0, tempStart = 0;
        
        for (size_t i = 0; i < arr.size(); i++) {
            currentSum += arr[i];
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
            
            if (currentSum < 0) {
                currentSum = 0;
                tempStart = i + 1;
            }
        }
        
        return {maxSum, start, end};
    }
    
    /**
     * Divide and Conquer approach
     * Time: O(n log n), Space: O(log n)
     */
    static int divideAndConquer(const std::vector<int>& arr, int left, int right) {
        if (left == right) {
            return arr[left];
        }
        
        int mid = left + (right - left) / 2;
        
        // Maximum subarray in left half
        int leftSum = divideAndConquer(arr, left, mid);
        
        // Maximum subarray in right half
        int rightSum = divideAndConquer(arr, mid + 1, right);
        
        // Maximum subarray crossing the middle
        int leftMax = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += arr[i];
            leftMax = std::max(leftMax, sum);
        }
        
        int rightMax = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += arr[i];
            rightMax = std::max(rightMax, sum);
        }
        
        int crossSum = leftMax + rightMax;
        
        return std::max({leftSum, rightSum, crossSum});
    }
    
    /**
     * Brute Force approach - O(n²)
     * Useful for understanding the problem
     */
    static int bruteForce(const std::vector<int>& arr) {
        if (arr.empty()) return 0;
        
        int maxSum = INT_MIN;
        
        for (size_t i = 0; i < arr.size(); i++) {
            int currentSum = 0;
            for (size_t j = i; j < arr.size(); j++) {
                currentSum += arr[j];
                maxSum = std::max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
    
    /**
     * Prefix Sum approach
     * Time: O(n), Space: O(n)
     */
    static int prefixSum(const std::vector<int>& arr) {
        if (arr.empty()) return 0;
        
        std::vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        
        for (size_t i = 1; i < arr.size(); i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
        
        int maxSum = arr[0];
        int minPrefix = 0;
        
        for (size_t i = 0; i < prefix.size(); i++) {
            maxSum = std::max(maxSum, prefix[i] - minPrefix);
            minPrefix = std::min(minPrefix, prefix[i]);
        }
        
        return maxSum;
    }
};

// Helper function to print array
void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

int main() {
    // Test cases
    std::vector<std::vector<int>> testCases = {
        {-2, 1, -3, 4, -1, 2, 1, -5, 4},  // Expected: 6
        {1, 2, 3, 4, 5},                   // Expected: 15
        {-5, -2, -8, -1, -4},              // Expected: -1
        {5},                               // Expected: 5
        {-1, -2, -3, -4}                   // Expected: -1
    };
    
    for (size_t i = 0; i < testCases.size(); i++) {
        std::cout << "Test Case " << (i + 1) << ": ";
        printArray(testCases[i]);
        std::cout << std::endl;
        
        int kadaneResult = MaxSubarray::kadane(testCases[i]);
        int dcResult = MaxSubarray::divideAndConquer(testCases[i], 0, testCases[i].size() - 1);
        int bfResult = MaxSubarray::bruteForce(testCases[i]);
        int psResult = MaxSubarray::prefixSum(testCases[i]);
        
        auto [maxSum, start, end] = MaxSubarray::kadaneWithIndices(testCases[i]);
        
        std::cout << "Kadane's Algorithm: " << kadaneResult << std::endl;
        std::cout << "Divide & Conquer: " << dcResult << std::endl;
        std::cout << "Brute Force: " << bfResult << std::endl;
        std::cout << "Prefix Sum: " << psResult << std::endl;
        std::cout << "Subarray indices: [" << start << ", " << end << "]" << std::endl;
        
        if (start >= 0 && end >= 0) {
            std::cout << "Subarray: ";
            printArray(std::vector<int>(testCases[i].begin() + start, 
                                      testCases[i].begin() + end + 1));
            std::cout << std::endl;
        }
        
        std::cout << "------------------------" << std::endl;
    }
    
    return 0;
}