/**
 * Best Time to Buy and Sell Stock - Java Implementation
 * ====================================================
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

import java.util.Arrays;

public class StockTradingJava {
    
    /**
     * Find maximum profit from buying and selling stock once.
     * 
     * @param prices Array of stock prices over time
     * @return Maximum profit possible, 0 if no profit possible
     * 
     * Example:
     *   Input: [7,1,5,3,6,4]
     *   Output: 5 (buy at 1, sell at 6)
     */
    public static int maxProfit(int[] prices) {
        // Handle edge cases
        if (prices == null || prices.length < 2) {
            return 0;  // Need at least 2 days to buy and sell
        }
        
        int minPriceSoFar = prices[0];    // Minimum price seen so far (best buy price)
        int maxProfitSoFar = 0;          // Maximum profit achieved so far
        
        // Iterate through prices starting from day 1 (index 1)
        for (int currentDay = 1; currentDay < prices.length; currentDay++) {
            int currentPrice = prices[currentDay];
            
            // Calculate profit if we sell at current price
            int currentProfit = currentPrice - minPriceSoFar;
            
            // Update maximum profit if current profit is better
            maxProfitSoFar = Math.max(maxProfitSoFar, currentProfit);
            
            // Update minimum price if current price is lower (better buy opportunity)
            minPriceSoFar = Math.min(minPriceSoFar, currentPrice);
        }
        
        return maxProfitSoFar;
    }
    
    /**
     * Brute force approach - check all buy/sell combinations.
     * Time: O(n²), Space: O(1)
     * Useful for understanding the problem better.
     */
    public static int maxProfitBruteForce(int[] prices) {
        if (prices == null || prices.length < 2) {
            return 0;
        }
        
        int maxProfit = 0;
        int arrayLength = prices.length;
        
        // Try all possible buy days
        for (int buyDay = 0; buyDay < arrayLength - 1; buyDay++) {
            // Try all possible sell days after buy day
            for (int sellDay = buyDay + 1; sellDay < arrayLength; sellDay++) {
                int profit = prices[sellDay] - prices[buyDay];
                maxProfit = Math.max(maxProfit, profit);
            }
        }
        
        return maxProfit;
    }
    
    /**
     * Advanced: Find the actual buy and sell days for maximum profit
     */
    public static int[] findBuySellDays(int[] prices) {
        if (prices == null || prices.length < 2) {
            return new int[]{-1, -1, 0};  // {buyDay, sellDay, maxProfit}
        }
        
        int minPriceSoFar = prices[0];
        int maxProfitSoFar = 0;
        int bestBuyDay = 0;
        int bestSellDay = 0;
        int currentBuyDay = 0;
        
        for (int currentDay = 1; currentDay < prices.length; currentDay++) {
            int currentPrice = prices[currentDay];
            int currentProfit = currentPrice - minPriceSoFar;
            
            // Update best days if we found better profit
            if (currentProfit > maxProfitSoFar) {
                maxProfitSoFar = currentProfit;
                bestBuyDay = currentBuyDay;
                bestSellDay = currentDay;
            }
            
            // Update minimum price and corresponding buy day
            if (currentPrice < minPriceSoFar) {
                minPriceSoFar = currentPrice;
                currentBuyDay = currentDay;
            }
        }
        
        return new int[]{bestBuyDay, bestSellDay, maxProfitSoFar};
    }
    
    /**
     * Print array in readable format
     */
    public static void printArray(int[] array) {
        System.out.print(Arrays.toString(array));
    }
    
    /**
     * Run comprehensive test cases
     */
    public static void runTestCases() {
        System.out.println("=== Best Time to Buy and Sell Stock (Java) Test Results ===\n");
        
        // Test cases with expected results
        int[][] testInputs = {
            {7, 1, 5, 3, 6, 4},     // Buy at 1, sell at 6
            {7, 6, 4, 3, 1},        // Prices only decrease
            {1, 2, 3, 4, 5},        // Prices only increase
            {2, 4, 1},              // Buy at 2, sell at 4
            {3, 3, 5, 0, 0, 3, 1, 4} // Buy at 0, sell at 4
        };
        
        int[] expectedResults = {5, 0, 4, 2, 4};
        
        String[] descriptions = {
            "Mixed prices - optimal buy/sell in middle",
            "Decreasing prices - no profit possible",
            "Increasing prices - buy first, sell last",
            "Small array with profit opportunity",
            "Complex case with multiple opportunities"
        };
        
        for (int i = 0; i < testInputs.length; i++) {
            int[] prices = testInputs[i];
            int expected = expectedResults[i];
            
            int resultOptimized = maxProfit(prices);
            int resultBruteForce = maxProfitBruteForce(prices);
            int[] buySellInfo = findBuySellDays(prices);
            
            System.out.println("Test Case " + (i + 1) + ": " + descriptions[i]);
            System.out.print("Input: ");
            printArray(prices);
            System.out.println();
            System.out.println("Expected: " + expected);
            System.out.println("Optimized Result: " + resultOptimized);
            System.out.println("Brute Force Result: " + resultBruteForce);
            
            if (buySellInfo.length >= 3 && buySellInfo[2] > 0) {  // If profit exists
                System.out.println("Buy on day " + buySellInfo[0] + 
                                 " (price: " + prices[buySellInfo[0]] + 
                                 "), sell on day " + buySellInfo[1] + 
                                 " (price: " + prices[buySellInfo[1]] + ")");
            } else if (buySellInfo.length >= 3 && buySellInfo[2] == 0) {
                System.out.println("No profitable trade possible");
            }
            
            // Verify correctness
            System.out.println(resultOptimized == expected ? 
                             "✅ Optimized: PASSED" : "❌ Optimized: FAILED");
            System.out.println(resultBruteForce == expected ? 
                             "✅ Brute Force: PASSED" : "❌ Brute Force: FAILED");
            
            System.out.println("-".repeat(60));
        }
        
        // Performance comparison for large array
        System.out.println("\n=== Performance Comparison ===");
        performanceTest();
    }
    
    /**
     * Performance test with larger arrays
     */
    public static void performanceTest() {
        // Generate large test array
        int[] largePrices = new int[10000];
        for (int i = 0; i < largePrices.length; i++) {
            largePrices[i] = (int)(Math.random() * 1000) + 1;  // Random prices 1-1000
        }
        
        System.out.println("Testing with array of size: " + largePrices.length);
        
        // Test optimized approach
        long startTime = System.nanoTime();
        int optimizedResult = maxProfit(largePrices);
        long optimizedTime = System.nanoTime() - startTime;
        
        System.out.println("Optimized approach: " + optimizedResult + 
                          " (Time: " + optimizedTime/1000000.0 + " ms)");
        
        // Note: Brute force would be too slow for 10000 elements
        System.out.println("Brute force approach: Skipped (would take too long for " + 
                          largePrices.length + " elements)");
    }
    
    /**
     * Demonstrate algorithm step by step
     */
    public static void demonstrateAlgorithm() {
        System.out.println("\n=== Algorithm Step-by-Step Demonstration ===");
        int[] prices = {7, 1, 5, 3, 6, 4};
        
        System.out.println("Input prices: " + Arrays.toString(prices));
        System.out.println("\nStep-by-step execution:");
        
        int minPriceSoFar = prices[0];
        int maxProfitSoFar = 0;
        
        System.out.println("Day 0: Price = " + prices[0] + 
                          ", Min Price = " + minPriceSoFar + 
                          ", Max Profit = " + maxProfitSoFar);
        
        for (int day = 1; day < prices.length; day++) {
            int currentPrice = prices[day];
            int currentProfit = currentPrice - minPriceSoFar;
            
            System.out.println("\nDay " + day + ": Price = " + currentPrice);
            System.out.println("  Current profit if sold today: " + currentProfit);
            
            maxProfitSoFar = Math.max(maxProfitSoFar, currentProfit);
            System.out.println("  Updated max profit: " + maxProfitSoFar);
            
            minPriceSoFar = Math.min(minPriceSoFar, currentPrice);
            System.out.println("  Updated min price: " + minPriceSoFar);
        }
        
        System.out.println("\nFinal maximum profit: " + maxProfitSoFar);
    }
    
    /**
     * Main method to run all tests and demonstrations
     */
    public static void main(String[] args) {
        runTestCases();
        demonstrateAlgorithm();
    }
}
