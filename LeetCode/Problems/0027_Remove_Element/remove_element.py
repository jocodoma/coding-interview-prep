from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        return self.twoPointers(nums, val)
        # return self.swapValues(nums, val)

    # time complexity: O(n), space complexity: O(1)
    def twoPointers(self, nums: List[int], val: int) -> int:
        if len(nums) == 0:
            return 0
          
        i = 0
        for n in nums:
            if n != val:
                nums[i] = n
                i += 1
        return i

    # time complexity: O(n), space complexity: O(1)
    def swapValues(self, nums: List[int], val: int) -> int:
        if len(nums) == 0:
            return 0
        
        l = 0
        r = len(nums) - 1
        while l <= r:
            if nums[l] == val:
                # nums[l], nums[r] = nums[r], nums[l]
                nums[l] = nums[r]
                r -= 1
            else:
                l += 1
        return l

nums = [3,2,2,3]
val = 3
size = Solution().removeElement(nums, val)
print(nums[:size])

nums = [0,1,2,2,3,0,4,2]
val = 2
size = Solution().removeElement(nums, val)
print(nums[:size])
