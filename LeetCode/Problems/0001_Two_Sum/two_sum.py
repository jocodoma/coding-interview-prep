from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # return self.__brute_forece(nums, target)
        # return self.__two_pass_hash_table(nums, target)
        return self.__one_pass_hash_table(nums, target)

    # time complexity: O(n**2), space complexity: O(1)
    def __brute_forece(self, nums: list[int], target: int) -> list[int]:
        for i, num in enumerate(nums):
            j = i + 1
            while j < len(nums):
                if target == (num + nums[j]):
                    return [i, j]
                j += 1

        return []

    # time complexity: O(2n) = O(n), space complexity: O(n)
    def __two_pass_hash_table(self, nums: list[int], target: int) -> list[int]:
        table = {}
        for i, num in enumerate(nums):
            table[num] = i

        for i, num in enumerate(nums):
            diff = target - num
            if diff in table and table[diff] != i:
                return [i, table[diff]]

        return []

    # time complexity: O(n), space complexity: O(n)
    def __one_pass_hash_table(self, nums: list[int], target: int) -> list[int]:
        table = {}
        for i, num in enumerate(nums):
            diff = target - num
            if diff in table:
                return [table[diff], i]
            table[num] = i

        return []


sol = Solution()
nums = [2, 7, 11, 15]
target = 9
print(f'{sol.twoSum(nums, target)}')

nums = [3, 2, 4]
target = 6
print(f'{sol.twoSum(nums, target)}')

nums = [3, 3]
target = 5
print(f'{sol.twoSum(nums, target)}')
