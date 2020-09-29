from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        i = m - 1
        j = n - 1
        k = m + n - 1

        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1

def printList(nums: List[int]) -> str:
    return ("[" + (', ').join(map(str, nums)) + "]")

nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]
m = 3
n = 3
print("Input: ")
print(printList(nums1) + ", m = " + str(m))
print(printList(nums2) + ", n = " + str(n))

Solution().merge(nums1, 3, nums2, 3)
print("\nOutput: ")
print(nums1)
