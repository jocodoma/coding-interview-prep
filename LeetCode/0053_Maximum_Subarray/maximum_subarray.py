class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0

        maxSoFar = currMax = nums[0]
        for num in nums[1:]:
            currMax = max(currMax+num, num)
            maxSoFar = max(maxSoFar, currMax)

        return maxSoFar
