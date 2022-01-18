from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0

        buy, sell = 0, 1
        maxProfitSoFar = 0
        while sell < len(prices):
            if prices[buy] < prices[sell]:
                profit = prices[sell] - prices[buy]
                maxProfitSoFar = max(maxProfitSoFar, profit)
                sell += 1
            else:
                buy = sell
                sell += 1
        return maxProfitSoFar


sol = Solution()
prices = [7,1,5,3,6,4]
output = sol.maxProfit(prices)
print(f'prices: {prices}, output: {output}')

prices = [7,6,4,3,1]
output = sol.maxProfit(prices)
print(f'prices: {prices}, output: {output}')
