from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        return self.__twoPointers(nums, val)
        # return self.__swapValues(nums, val)

    # time complexity: O(n), space complexity: O(1)
    def __twoPointers(self, nums: List[int], val: int) -> int:
        if len(nums) == 0:
            return 0

        i = 0
        for n in nums:
            if n != val:
                nums[i] = n
                i += 1
        return i

    # time complexity: O(n), space complexity: O(1)
    def __swapValues(self, nums: List[int], val: int) -> int:
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

def printList(nums: List[int]) -> str:
    return (', ').join(map(str, nums))

nums = [3,2,2,3]
val = 3
print("Input: nums = [" + printList(nums) + "], val = " + str(val))

size = Solution().removeElement(nums, val)
print("Output: nums = [" + printList(nums[:size]) + "]\n")

nums = [0,1,2,2,3,0,4,2]
val = 2
print("Input: nums = [" + printList(nums) + "], val = " + str(val))

size = Solution().removeElement(nums, val)
print("Output: nums = [" + printList(nums[:size]) + "]")
