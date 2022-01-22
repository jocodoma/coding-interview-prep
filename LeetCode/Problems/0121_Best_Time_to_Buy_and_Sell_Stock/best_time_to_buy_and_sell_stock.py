from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # return self.__bruteForce(prices)
        return self.__twoPointer(prices)

    # time complexity: O(n**2), space complexity: O(1)
    def __bruteForce(self, prices: List[int]) -> int:
        maxProfitSoFar = 0
        for buy in range(len(prices)):
            for sell in range(buy+1, len(prices)):
                profit = prices[sell] - prices[buy]
                maxProfitSoFar = max(maxProfitSoFar, profit)
        return maxProfitSoFar

    # keep track both minimum price and maximum profit
    # time complexity: O(n), space complexity: O(1)
    def __twoPointer(self, prices: List[int]) -> int:
        maxProfitSoFar = 0
        buy, sell = 0, 1
        while sell < len(prices):
            profit = prices[sell] - prices[buy]
            if profit > 0:
                if profit > maxProfitSoFar:
                    maxProfitSoFar = profit
                sell += 1
            else:
                buy = sell
                sell += 1
        return maxProfitSoFar


prices = [7,1,5,3,6,4]
print(f'Input:  {prices}')
print(f'Output: {Solution().maxProfit(prices)}\n')

prices = [7,6,4,3,1]
print(f'Input:  {prices}')
print(f'Output: {Solution().maxProfit(prices)}\n')
