from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lookupTable = {}
        for i, n in enumerate(nums):
            diff = target - n
            if diff in lookupTable:
                return [lookupTable[diff], i]
            else:
                lookupTable[n] = i
        return []

print(Solution().twoSum([2, 7, 11, 15], 10))
