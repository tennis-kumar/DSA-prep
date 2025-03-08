# Problem: Best Time to Buy and Sell Stock
# Difficulty: Easy
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        # optimal solution is using two pointers and sliding wnidow
        # time complexity is linear O(n), space complexity is O(1)
        # maxProfit = 0
        # left, right = 0, 1 # left = buy, right = sell

        # while right < len(prices):

        #     if prices[left] < prices[right]:
        #         profit = prices[right] - prices[left]
        #         maxProfit = max(maxProfit, profit)
        #     else:
        #         left = right
        #     right += 1

        # return maxProfit


        #### Alternative Approach ,

        mini = float('inf')
        maxi = 0

        for price in prices:
            mini = min(mini, price)
            maxi = max(maxi, price - mini)
        return maxi


        return 0 # no transactions done