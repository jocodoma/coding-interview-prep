from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # return self.__bruteForceO3(nums)
        # return self.__bruteForceO2(nums)
        # return self.__onePassDP(nums)
        return self.__divideAndConquer(nums)

    # time complexity: O(n**3), space complexity: O(1)
    def __bruteForceO3(self, nums: List[int]) -> int:
        maxSum = nums[0]
        for i in range(len(nums)):
            for j in range(len(nums)):
                currSum = 0
                for k in range(i, j+1):
                    currSum += nums[k]
                maxSum = max(maxSum, currSum)
        return maxSum

    # time complexity: O(n**2), space complexity: O(1)
    def __bruteForceO2(self, nums: List[int]) -> int:
        # return self.__bruteForceO2v1(nums)
        return self.__bruteForceO2v2(nums)

    def __bruteForceO2v1(self, nums: List[int]) -> int:
        global_maxSum = nums[0]
        for i in range(len(nums)):
            local_maxSum = currSum = nums[i]
            for j in range(i+1, len(nums)):
                currSum += nums[j]
                local_maxSum = max(local_maxSum, currSum)
            global_maxSum = max(global_maxSum, local_maxSum)
        return global_maxSum

    def __bruteForceO2v2(self, nums: List[int]) -> int:
        maxSum = nums[0]
        for i in range(len(nums)):
            currSum = nums[i]
            maxSum = max(maxSum, currSum)
            for j in range(i+1, len(nums)):
                currSum += nums[j]
                maxSum = max(maxSum, currSum)
        return maxSum

    # Kadane's algorithm with dynamic programming
    # time complexity: O(n), space complexity: O(1)
    def __onePassDP(self, nums: List[int]) -> int:
        return self.__onePassDPv1(nums)
        # return self.__onePassDPv2(nums)

    def __onePassDPv1(self, nums: List[int]) -> int:
        global_maxSum = local_maxSum = nums[0]
        for num in nums[1:]:
            local_maxSum = max(num, local_maxSum+num)
            if local_maxSum > global_maxSum:
                global_maxSum = local_maxSum
        return global_maxSum

    def __onePassDPv2(self, nums: List[int]) -> int:
        l = r = 0
        global_maxSum = local_maxSum = nums[0]
        for i in range(1, len(nums)):
            currSum = local_maxSum + nums[i]
            if nums[i] > currSum:
                local_maxSum = nums[i]
                l = i
            else:
                local_maxSum = currSum

            if local_maxSum > global_maxSum:
                global_maxSum = local_maxSum
                r = i
        print(f'l: {l}, r: {r}')
        return global_maxSum

    # time complexity: O(nlogn), space complexity: O(logn)
    def __divideAndConquer(self, nums: List[int]) -> int:
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
print(f'Input:  {nums}')
print(f'Output: {Solution().maxSubArray(nums)}\n')

nums = [1,2,-1,-2,2,1,-2,1]
print(f'Input:  {nums}')
print(f'Output: {Solution().maxSubArray(nums)}\n')

nums = [5,4,-1,7,8]
print(f'Input:  {nums}')
print(f'Output: {Solution().maxSubArray(nums)}\n')

nums = [1]
print(f'Input:  {nums}')
print(f'Output: {Solution().maxSubArray(nums)}\n')

nums = [0]
print(f'Input:  {nums}')
print(f'Output: {Solution().maxSubArray(nums)}\n')

nums = [-1]
print(f'Input:  {nums}')
print(f'Output: {Solution().maxSubArray(nums)}\n')

# nums = []
# print(f'Input:  {nums}')
# print(f'Output: {Solution().maxSubArray(nums)}\n')

# nums = [-2147483647]
# print(f'Input:  {nums}')
# print(f'Output: {Solution().maxSubArray(nums)}\n')
