/**
 * Best Time to Buy and Sell Stock
 * ===============================
 * 
 * Problem: Given an array of stock prices, find the maximum profit from one buy and one sell.
 * You must buy before you sell. If no profit possible, return 0.
 * 
 * Approach: Single Pass with Min Price Tracking
 * - Keep track of minimum price seen so far (best buy price)
 * - For each price, calculate profit if we sell at current price
 * - Update maximum profit if current profit is better
 * - Update minimum price if current price is lower
 * 
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(1) - only using few variables
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class StockTrader {
public:
    /**
     * Find maximum profit from buying and selling stock once.
     * 
     * @param prices Vector of stock prices over time
     * @return Maximum profit possible, 0 if no profit possible
     * 
     * Example:
     *   Input: [7,1,5,3,6,4]
     *   Output: 5 (buy at 1, sell at 6)
     */
    static int maxProfit(const std::vector<int>& prices) {
        // Handle edge cases
        if (prices.empty() || prices.size() < 2) {
            return 0;  // Need at least 2 days to buy and sell
        }
        
        int minPriceSoFar = prices[0];    // Minimum price seen so far (best buy price)
        int maxProfitSoFar = 0;          // Maximum profit achieved so far
        
        // Iterate through prices starting from day 1 (index 1)
        for (int currentDay = 1; currentDay < prices.size(); currentDay++) {
            int currentPrice = prices[currentDay];
            
            // Calculate profit if we sell at current price
            int currentProfit = currentPrice - minPriceSoFar;
            
            // Update maximum profit if current profit is better
            maxProfitSoFar = std::max(maxProfitSoFar, currentProfit);
            
            // Update minimum price if current price is lower (better buy opportunity)
            minPriceSoFar = std::min(minPriceSoFar, currentPrice);
        }
        
        return maxProfitSoFar;
    }
    
    /**
     * Brute force approach - check all buy/sell combinations.
     * Time: O(n²), Space: O(1)
     * Useful for understanding the problem better.
     */
    static int maxProfitBruteForce(const std::vector<int>& prices) {
        if (prices.empty() || prices.size() < 2) {
            return 0;
        }
        
        int maxProfit = 0;
        int arraySize = prices.size();
        
        // Try all possible buy days
        for (int buyDay = 0; buyDay < arraySize - 1; buyDay++) {
            // Try all possible sell days after buy day
            for (int sellDay = buyDay + 1; sellDay < arraySize; sellDay++) {
                int profit = prices[sellDay] - prices[buyDay];
                maxProfit = std::max(maxProfit, profit);
            }
        }
        
        return maxProfit;
    }
    
    /**
     * Print vector in readable format
     */
    static void printVector(const std::vector<int>& vec) {
        std::cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i];
            if (i < vec.size() - 1) std::cout << ", ";
        }
        std::cout << "]";
    }
    
    /**
     * Run comprehensive test cases
     */
    static void runTestCases() {
        std::cout << "=== Best Time to Buy and Sell Stock Test Results ===\n\n";
        
        // Test cases with expected results
        std::vector<std::pair<std::vector<int>, int>> testCases = {
            {{7, 1, 5, 3, 6, 4}, 5},        // Buy at 1, sell at 6
            {{7, 6, 4, 3, 1}, 0},           // Prices only decrease
            {{1, 2, 3, 4, 5}, 4},           // Prices only increase
            {{2, 4, 1}, 2},                 // Buy at 2, sell at 4
            {{3, 3, 5, 0, 0, 3, 1, 4}, 4}  // Buy at 0, sell at 4
        };
        
        std::vector<std::string> descriptions = {
            "Mixed prices - optimal buy/sell in middle",
            "Decreasing prices - no profit possible",
            "Increasing prices - buy first, sell last",
            "Small array with profit opportunity",
            "Complex case with multiple opportunities"
        };
        
        for (int i = 0; i < testCases.size(); i++) {
            const auto& prices = testCases[i].first;
            int expected = testCases[i].second;
            
            int resultOptimized = maxProfit(prices);
            int resultBruteForce = maxProfitBruteForce(prices);
            
            std::cout << "Test Case " << (i + 1) << ": " << descriptions[i] << "\n";
            std::cout << "Input: ";
            printVector(prices);
            std::cout << "\n";
            std::cout << "Expected: " << expected << "\n";
            std::cout << "Optimized Result: " << resultOptimized << "\n";
            std::cout << "Brute Force Result: " << resultBruteForce << "\n";
            
            // Verify correctness
            if (resultOptimized == expected) {
                std::cout << "✅ Optimized: PASSED\n";
            } else {
                std::cout << "❌ Optimized: FAILED\n";
            }
            
            if (resultBruteForce == expected) {
                std::cout << "✅ Brute Force: PASSED\n";
            } else {
                std::cout << "❌ Brute Force: FAILED\n";
            }
            
            std::cout << std::string(50, '-') << "\n";
        }
    }
};

/**
 * Main function to run all test cases
 */
int main() {
    StockTrader::runTestCases();
    return 0;
}
