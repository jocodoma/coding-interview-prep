class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 0: return 0
        if n < 3: return n
        a, b = 1, 2
        for _ in range(2, n):
            a, b = b, a + b
        return b
