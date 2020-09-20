from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0

        maxSoFar = currMax = nums[0]
        for num in nums[1:]:
            currMax = max(currMax+num, num)
            maxSoFar = max(maxSoFar, currMax)

        return maxSoFar

print(Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
print(Solution().maxSubArray([1]))
print(Solution().maxSubArray([0]))
print(Solution().maxSubArray([-1]))
