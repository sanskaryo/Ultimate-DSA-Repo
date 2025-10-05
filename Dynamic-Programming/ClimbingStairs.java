/**
 * Problem: Climbing Stairs
 * 
 * You are climbing a staircase of n steps. 
 * Each time you can climb 1 or 2 steps. 
 * Find the number of distinct ways to reach the top.
 * 
 * Example 1: n=2 → 2 ways (1+1, 2)
 * Example 2: n=3 → 3 ways (1+1+1, 1+2, 2+1)
 * 
 * Time: O(n) | Space: O(1)  (optimized DP)
 * 
 * Key Insight: Fibonacci relation
 * - dp[i] = dp[i-1] + dp[i-2]
 * - Because you can reach step i from (i-1) or (i-2)
 */
public class ClimbingStairs {

    // Optimized DP (Fibonacci)
    public static int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2, curr = 0;
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    // Recursive (inefficient, O(2^n))
    public static int climbStairsRecursive(int n) {
        if (n <= 2) return n;
        return climbStairsRecursive(n-1) + climbStairsRecursive(n-2);
    }

    // Memoization
    public static int climbStairsMemo(int n) {
        return climbStairsMemoHelper(n, new int[n+1]);
    }
    private static int climbStairsMemoHelper(int n, int[] memo) {
        if (n <= 2) return n;
        if (memo[n] != 0) return memo[n];
        return memo[n] = climbStairsMemoHelper(n-1, memo) + climbStairsMemoHelper(n-2, memo);
    }

    // Tabulation
    public static int climbStairsTab(int n) {
        if (n <= 2) return n;
        int[] dp = new int[n+1];
        dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }

    public static void main(String[] args) {
        int[] tests = {1,2,3,5,10};
        for (int n : tests) {
            System.out.println("n=" + n + " → " + climbStairs(n) + " ways");
        }
    }
}

/**
 * Learnings:
 * - Classic DP → Fibonacci pattern
 * - Optimized DP reduces space to O(1)
 * - Related: Min Cost Climbing Stairs, House Robber, Decode Ways
 */
