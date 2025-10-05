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

    /**
     * Compute the maximum profit obtainable from a single buy-sell transaction given daily stock prices.
     *
     * @param prices an array where prices[i] is the stock price on day i
     * @return the maximum profit achievable by buying once and selling later; `0` if no profit is possible or input is null/too short
     */
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

    /**
     * Computes the maximum profit obtainable from a single buy-and-sell transaction using brute-force comparison.
     *
     * @param prices array of stock prices where prices[i] is the price on day i
     * @return the maximum profit achievable by buying on one day and selling on a later day; 0 if no positive profit exists
     */
    public static int maxProfitBruteForce(int[] prices) {
        int maxProfit = 0;
        for (int i = 0; i < prices.length; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                maxProfit = Math.max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit;
    }

    /**
     * Demonstrates example usage of {@link #maxProfit(int[])} by running two sample price arrays and printing their profits.
     *
     * Prints the maximum profit for prices1 ({7, 1, 5, 3, 6, 4}) and prices2 ({7, 6, 4, 3, 1}) to standard output
     * (expected output: 5 and 0).
     *
     * @param args command-line arguments (ignored)
     */
    public static void main(String[] args) {
        int[] prices1 = {7, 1, 5, 3, 6, 4};
        int[] prices2 = {7, 6, 4, 3, 1};

        System.out.println(maxProfit(prices1)); // 5
        System.out.println(maxProfit(prices2)); // 0
    }
}