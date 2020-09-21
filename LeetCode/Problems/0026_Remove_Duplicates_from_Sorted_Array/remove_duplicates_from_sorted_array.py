from typing import List

class Solution:
    # time complexity: O(n), space complexity: O(1)
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        i = 0
        for n in nums:
            if(nums[i] != n):
                i += 1
                nums[i] = n

        return i+1

nums = [1, 1, 2]
size = Solution().removeDuplicates(nums)
print(nums[:size])

nums = [0,0,1,1,1,2,2,3,3,4]
size = Solution().removeDuplicates(nums)
print(nums[:size])
