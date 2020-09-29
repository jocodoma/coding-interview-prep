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

def printList(nums: List[int]) -> str:
    return ("[" +  (', ').join(map(str, nums)) + "]")

nums = [-2,1,-3,4,-1,2,1,-5,4]
print("Input: " + printList(nums))
print("Output: " + str(Solution().maxSubArray(nums)))

nums = [1]
print("Input: " + printList(nums))
print("Output: " + str(Solution().maxSubArray(nums)))

nums = [0]
print("Input: " + printList(nums))
print("Output: " + str(Solution().maxSubArray(nums)))

nums = [-1]
print("Input: " + printList(nums))
print("Output: " + str(Solution().maxSubArray(nums)))

nums = [-2147483647]
print("Input: " + printList(nums))
print("Output: " + str(Solution().maxSubArray(nums)))
