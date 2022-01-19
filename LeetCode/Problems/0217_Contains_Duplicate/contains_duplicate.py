from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # return self.__bruteForce(nums)
        # return self.__sorting(nums)
        return self.__hashset(nums)

    # time complexity: O(n**2), space complexity: O(1)
    def __bruteForce(self, nums: List[int]) -> bool:
        for i, num in enumerate(nums):
            for j in range(i+1, len(nums)):
                if num == nums[j]:
                    return True

        return False

    # time complexity: O(nlogn) due to sorting
    # space complexity: O(1) without considering the space taken by sorting
    def __sorting(self, nums: List[int]) -> bool:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i-1] == nums[i]:
                return True

        return False

    # time complexity: O(n), space complexity: O(n)
    def __hashset(self, nums: List[int]) -> bool:
        table = set()
        for num in nums:
            if num in table:
                return True
            else:
                table.add(num)

        return False


sol = Solution()

nums = [1,2,3,1]
print(f'Input:  {nums}')
print(f'Output: {sol.containsDuplicate(nums)}\n')

nums = [1,2,3,4]
print(f'Input:  {nums}')
print(f'Output: {sol.containsDuplicate(nums)}\n')

nums = [1,1,1,3,3,4,3,2,4,2]
print(f'Input:  {nums}')
print(f'Output: {sol.containsDuplicate(nums)}\n')
