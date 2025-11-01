"""
Best Time to Buy and Sell Stock - Python Implementation
======================================================

Problem: Given an array of stock prices, find the maximum profit from one buy and one sell.
You must buy before you sell. If no profit possible, return 0.

Approach: Single Pass with Min Price Tracking
- Keep track of minimum price seen so far (best buy price)
- For each price, calculate profit if we sell at current price
- Update maximum profit if current profit is better
- Update minimum price if current price is lower

Time Complexity: O(n) - single pass through array
Space Complexity: O(1) - only using few variables

Examples:
- [7,1,5,3,6,4] → 5 (buy at 1, sell at 6)
- [7,6,4,3,1] → 0 (prices only decrease)
- [1,2,3,4,5] → 4 (buy at 1, sell at 5)
"""

import time
import random
from typing import List, Tuple, Optional


def max_profit_optimized(prices: List[int]) -> int:
    """
    Find maximum profit from buying and selling stock once (optimized).
    
    Args:
        prices: List of stock prices over time
        
    Returns:
        Maximum profit possible, 0 if no profit possible
        
    Example:
        >>> max_profit_optimized([7, 1, 5, 3, 6, 4])
        5
        >>> max_profit_optimized([7, 6, 4, 3, 1])
        0
    """
    # Handle edge cases
    if not prices or len(prices) < 2:
        return 0  # Need at least 2 days to buy and sell
    
    min_price_so_far = prices[0]    # Minimum price seen so far (best buy price)
    max_profit_so_far = 0          # Maximum profit achieved so far
    
    # Iterate through prices starting from day 1 (index 1)
    for current_day in range(1, len(prices)):
        current_price = prices[current_day]
        
        # Calculate profit if we sell at current price
        current_profit = current_price - min_price_so_far
        
        # Update maximum profit if current profit is better
        max_profit_so_far = max(max_profit_so_far, current_profit)
        
        # Update minimum price if current price is lower (better buy opportunity)
        min_price_so_far = min(min_price_so_far, current_price)
    
    return max_profit_so_far


def max_profit_brute_force(prices: List[int]) -> int:
    """
    Brute force approach - check all buy/sell combinations.
    Time: O(n²), Space: O(1)
    Useful for understanding the problem better.
    """
    if not prices or len(prices) < 2:
        return 0
    
    max_profit = 0
    array_length = len(prices)
    
    # Try all possible buy days
    for buy_day in range(array_length - 1):
        # Try all possible sell days after buy day
        for sell_day in range(buy_day + 1, array_length):
            profit = prices[sell_day] - prices[buy_day]
            max_profit = max(max_profit, profit)
    
    return max_profit


def find_buy_sell_days(prices: List[int]) -> Tuple[int, int, int]:
    """
    Find the actual buy and sell days for maximum profit.
    
    Returns:
        Tuple of (buy_day, sell_day, max_profit)
    """
    if not prices or len(prices) < 2:
        return (-1, -1, 0)  # Invalid result
    
    min_price_so_far = prices[0]
    max_profit_so_far = 0
    best_buy_day = 0
    best_sell_day = 0
    current_buy_day = 0
    
    for current_day in range(1, len(prices)):
        current_price = prices[current_day]
        current_profit = current_price - min_price_so_far
        
        # Update best days if we found better profit
        if current_profit > max_profit_so_far:
            max_profit_so_far = current_profit
            best_buy_day = current_buy_day
            best_sell_day = current_day
        
        # Update minimum price and corresponding buy day
        if current_price < min_price_so_far:
            min_price_so_far = current_price
            current_buy_day = current_day
    
    return (best_buy_day, best_sell_day, max_profit_so_far)


def max_profit_with_multiple_transactions(prices: List[int], k: int = 2) -> int:
    """
    Advanced: Allow up to k transactions (buy-sell pairs).
    This is beyond the basic problem but shows extension possibilities.
    """
    if not prices or len(prices) < 2 or k == 0:
        return 0
    
    # If k is large enough, we can do as many transactions as we want
    if k >= len(prices) // 2:
        return sum(max(prices[i] - prices[i-1], 0) for i in range(1, len(prices)))
    
    # Dynamic programming approach for limited transactions
    buy = [-prices[0]] * k
    sell = [0] * k
    
    for price in prices[1:]:
        for j in range(k-1, -1, -1):
            sell[j] = max(sell[j], buy[j] + price)
            if j > 0:
                buy[j] = max(buy[j], sell[j-1] - price)
            else:
                buy[j] = max(buy[j], -price)
    
    return sell[-1] if k > 0 else 0


def run_test_cases():
    """Test the stock trading implementations with various cases."""
    
    print("=== Best Time to Buy and Sell Stock (Python) Test Results ===\n")
    
    test_cases = [
        {
            "input": [7, 1, 5, 3, 6, 4],
            "expected": 5,
            "description": "Mixed prices - optimal buy/sell in middle"
        },
        {
            "input": [7, 6, 4, 3, 1],
            "expected": 0,
            "description": "Decreasing prices - no profit possible"
        },
        {
            "input": [1, 2, 3, 4, 5],
            "expected": 4,
            "description": "Increasing prices - buy first, sell last"
        },
        {
            "input": [2, 4, 1],
            "expected": 2,
            "description": "Small array with profit opportunity"
        },
        {
            "input": [3, 3, 5, 0, 0, 3, 1, 4],
            "expected": 4,
            "description": "Complex case with multiple opportunities"
        }
    ]
    
    for i, test in enumerate(test_cases, 1):
        prices = test["input"]
        expected = test["expected"]
        
        # Test both approaches
        result_optimized = max_profit_optimized(prices)
        result_brute_force = max_profit_brute_force(prices)
        buy_day, sell_day, profit = find_buy_sell_days(prices)
        
        print(f"Test Case {i}: {test['description']}")
        print(f"Input: {prices}")
        print(f"Expected: {expected}")
        print(f"Optimized Result: {result_optimized}")
        print(f"Brute Force Result: {result_brute_force}")
        
        if profit > 0:
            print(f"Buy on day {buy_day} (price: {prices[buy_day]}), "
                  f"sell on day {sell_day} (price: {prices[sell_day]})")
        
        # Verify correctness
        print("✅ Optimized: PASSED" if result_optimized == expected else "❌ Optimized: FAILED")
        print("✅ Brute Force: PASSED" if result_brute_force == expected else "❌ Brute Force: FAILED")
        
        print("-" * 60)


def performance_test():
    """Performance comparison between optimized and brute force approaches."""
    
    print("\n=== Performance Comparison ===")
    
    # Test with different array sizes
    sizes = [100, 1000, 5000]
    
    for size in sizes:
        # Generate random prices
        prices = [random.randint(1, 1000) for _ in range(size)]
        
        print(f"\nTesting with array of size: {size}")
        
        # Test optimized approach
        start_time = time.time()
        optimized_result = max_profit_optimized(prices)
        optimized_time = (time.time() - start_time) * 1000
        
        print(f"Optimized approach: {optimized_result} (Time: {optimized_time:.2f} ms)")
        
        # Test brute force only for smaller arrays (to avoid long wait)
        if size <= 1000:
            start_time = time.time()
            brute_result = max_profit_brute_force(prices)
            brute_time = (time.time() - start_time) * 1000
            
            print(f"Brute force approach: {brute_result} (Time: {brute_time:.2f} ms)")
            print(f"Speedup: {brute_time/optimized_time:.1f}x faster")
        else:
            print("Brute force approach: Skipped (would take too long)")


def demonstrate_algorithm():
    """Demonstrate the algorithm step by step."""
    
    print("\n=== Algorithm Step-by-Step Demonstration ===")
    
    prices = [7, 1, 5, 3, 6, 4]
    print(f"Input prices: {prices}")
    print(f"Array represents prices on days: {list(range(len(prices)))}")
    print("\nStep-by-step execution:")
    
    min_price_so_far = prices[0]
    max_profit_so_far = 0
    
    print(f"Day 0: Price = {prices[0]}, Min Price = {min_price_so_far}, Max Profit = {max_profit_so_far}")
    
    for day in range(1, len(prices)):
        current_price = prices[day]
        current_profit = current_price - min_price_so_far
        
        print(f"\nDay {day}: Price = {current_price}")
        print(f"  Current profit if sold today: {current_profit}")
        
        max_profit_so_far = max(max_profit_so_far, current_profit)
        print(f"  Updated max profit: {max_profit_so_far}")
        
        min_price_so_far = min(min_price_so_far, current_price)
        print(f"  Updated min price: {min_price_so_far}")
    
    print(f"\nFinal maximum profit: {max_profit_so_far}")


def test_advanced_features():
    """Test advanced features like multiple transactions."""
    
    print("\n=== Advanced Features Test ===")
    
    prices = [3, 3, 5, 0, 0, 3, 1, 4]
    
    print(f"Input prices: {prices}")
    print(f"Single transaction max profit: {max_profit_optimized(prices)}")
    print(f"Two transactions max profit: {max_profit_with_multiple_transactions(prices, 2)}")
    print(f"Unlimited transactions max profit: {max_profit_with_multiple_transactions(prices, len(prices)//2)}")


if __name__ == "__main__":
    # Run all tests and demonstrations
    run_test_cases()
    performance_test()
    demonstrate_algorithm()
    test_advanced_features()
    
    # Interactive test
    print("\n" + "="*60)
    print("Try your own test case!")
    print("Example: Enter prices separated by commas: 7,1,5,3,6,4")
    
    try:
        user_input = input("Enter stock prices: ").strip()
        if user_input:
            prices = [int(x.strip()) for x in user_input.split(",")]
            result = max_profit_optimized(prices)
            buy_day, sell_day, profit = find_buy_sell_days(prices)
            
            print(f"Input: {prices}")
            print(f"Maximum profit: {result}")
            if profit > 0:
                print(f"Strategy: Buy on day {buy_day} (price: {prices[buy_day]}), "
                      f"sell on day {sell_day} (price: {prices[sell_day]})")
            else:
                print("Strategy: Don't trade (no profit possible)")
    except (ValueError, KeyboardInterrupt):
        print("Invalid input or cancelled. Exiting...")
