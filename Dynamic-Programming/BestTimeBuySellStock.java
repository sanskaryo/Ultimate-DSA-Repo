/**
 * Problem: Best Time to Buy and Sell Stock
 *
 * You are given an array prices[] where prices[i] is the stock price on day i.
 * Choose a day to buy and a future day to sell to maximize profit.
 * If no profit is possible, return 0.
 *
 * Example 1:
 * Input: [7,1,5,3,6,4] → Output: 5
 * Explanation: Buy at 1, sell at 6 → profit = 5
 *
 * Example 2:
 * Input: [7,6,4,3,1] → Output: 0
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Approach:
 * - Track the minimum price seen so far
 * - For each day, compute profit = price - minPrice
 * - Update maxProfit if current profit is larger
 */

public class BestTimeBuySellStock {

    // Optimized DP approach
    public static int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1) return 0;

        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; // update minimum
            } else {
                maxProfit = Math.max(maxProfit, price - minPrice); // update profit
            }
        }
        return maxProfit;
    }

    // Brute Force for comparison (O(n²))
    public static int maxProfitBruteForce(int[] prices) {
        int maxProfit = 0;
        for (int i = 0; i < prices.length; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                maxProfit = Math.max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit;
    }

    public static void main(String[] args) {
        int[] prices1 = {7, 1, 5, 3, 6, 4};
        int[] prices2 = {7, 6, 4, 3, 1};

        System.out.println(maxProfit(prices1)); // 5
        System.out.println(maxProfit(prices2)); // 0
    }
}
