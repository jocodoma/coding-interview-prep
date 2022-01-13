from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        return self.__bruteForce(nums)
        # return self.__onePassDP(nums)
        # return self.__divideAndConquer(nums)

    # time complexity: O(n^2), space complexity: O(1)
    def __bruteForce(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        maxSum = nums[0]
        for i in range(len(nums)):
            currMaxSum = nums[i]
            maxSum = max(maxSum, currMaxSum)

            for j in range(i+1, len(nums)):
                currMaxSum += nums[j]
                maxSum = max(maxSum, currMaxSum)

        return maxSum

    # Kadane's algorithm with dynamic programming
    # time complexity: O(n), space complexity: O(1)
    def __onePassDP(self, nums: List[int]) -> int:
        if not nums:
            return 0

        maxSum = currSum = nums[0]
        for num in nums[1:]:
            currSum = max(currSum+num, num)
            maxSum = max(maxSum, currSum)

        return maxSum

    # time complexity: O(nlogn), space complexity: O(logn)
    def __divideAndConquer(self, nums: List[int]) -> int:
        if not nums:
            return 0

        return self.__findMaxSum(nums, 0, len(nums)-1)

    def __findMaxSum(self, nums: List[int], l: int, r: int) -> int:
        if l >= r:
            return nums[l]

        mid = l + (r-l)//2
        leftSubMax = self.__findMaxSum(nums, l, mid-1)
        rightSubMax = self.__findMaxSum(nums, mid+1, r)

        # cross mid
        midLeftSubMax = midRightSubMax = nums[mid]

        currSum = midLeftSubMax
        i = mid - 1
        while i >= l:
            currSum += nums[i]
            midLeftSubMax = max(midLeftSubMax, currSum)
            i -= 1

        currSum = midRightSubMax
        j = mid + 1
        while j <= r:
            currSum += nums[j]
            midRightSubMax = max(midRightSubMax, currSum)
            j += 1

        midSubMax = midLeftSubMax + midRightSubMax - nums[mid]

        return max(leftSubMax, rightSubMax, midSubMax)

def printList(nums: List[int]) -> str:
    return ("[" +  (', ').join(map(str, nums)) + "]")

nums = [-2,1,-3,4,-1,2,1,-5,4]
print("Input: " + printList(nums))
print("Output: " + str(Solution().maxSubArray(nums)))
print()

nums = [1,2,-1,-2,2,1,-2,1]
print("Input: " + printList(nums))
print("Output: " + str(Solution().maxSubArray(nums)))
print()

nums = [1]
print("Input: " + printList(nums))
print("Output: " + str(Solution().maxSubArray(nums)))
print()

nums = [0]
print("Input: " + printList(nums))
print("Output: " + str(Solution().maxSubArray(nums)))
print()

nums = [-1]
print("Input: " + printList(nums))
print("Output: " + str(Solution().maxSubArray(nums)))
print()

# nums = [-2147483647]
# print("Input: " + printList(nums))
# print("Output: " + str(Solution().maxSubArray(nums)))
# print()
