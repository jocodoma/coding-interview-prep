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

def printList(nums: List[int]) -> str:
    return('[' + ', '.join(map(str, nums)) + ']')

nums = [1,1,2]
print("Input: " + printList(nums))
size = Solution().removeDuplicates(nums)
print("Output: " + printList(nums[:size]))

nums = [0,0,1,1,1,2,2,3,3,4]
print("\nInput: " + printList(nums))
size = Solution().removeDuplicates(nums)
print("Output: " + printList(nums[:size]))
