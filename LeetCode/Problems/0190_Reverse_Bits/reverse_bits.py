class Solution:
    def reverseBits(self, n: int) -> int:
        return self.__onePass(n)
        # return self.__twoPointers(n)

    # time complexity: O(n), space complexity: O(1)
    def __onePass(self, n: int) -> int:
        ans = 0
        for i in range(32):
            bit = n >> i & 1
            ans = ans << 1
            ans = ans | bit

            # the above lines are same as follow
            # ans = ans << 1 | n >> i & 1
        return ans

    def __swapBits(self, n, l: int, r: int) -> int:
        #  do swap if XOR is true, otherwise return n
        #  swap binary bit -> bit flipping (XOR)
        bitL = n >> l & 1
        bitR = n >> r & 1
        if bitL ^ bitR:
            n = n ^ 1 << l
            n = n ^ 1 << r
        return n

    # time complexity: O(n/2) = O(n), space complexity: O(1)
    def __twoPointers(self, n: int) -> int:
        l, r = 31, 0
        while l > r:
            n = self.__swapBits(n, l, r)
            l -= 1
            r += 1
        return n


n = 43261596
ans = Solution().reverseBits(n)
print(f'Input:  {n}, {n:032b}')
print(f'Output: {ans}, {ans:032b}\n')

n = 4294967293
ans = Solution().reverseBits(n)
print(f'Input:  {n}, {n:032b}')
print(f'Output: {ans}, {ans:032b}\n')
