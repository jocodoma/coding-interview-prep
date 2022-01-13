class Solution:
    def reverse_bits_str(self, n: str) -> str:
        return n[::-1]

    def reverse_bits_str2(self, n: str) -> str:
        n_list = list(n)
        l = 0
        r = len(n_list) - 1
        while(l < r):
            n_list[l], n_list[r] = n_list[r], n_list[l]
            l += 1
            r -= 1
        return ''.join(n_list)

    def __swap_bits(self, n: int, i: int, j: int) -> int:
        if (n >> i & 1) ^ (n >> j & 1):
            bit_mask = 1 << i | 1 << j
            n ^= bit_mask

        return n

    def reverse_bits_int(self, n: int) -> int:
        print(f'n: {n:08b}')
        r = 0
        l = 7

        # while l > r:
        #     n = self.__swap_bits(n, l, r)
        #     r += 1
        #     l -= 1

        while(l > r):
            l_bit = (n & 1 << l) >> l & 1
            r_bit = (n & 1 << r) >> r & 1
            # print(f'l: {l}, r: {r}, l_bit: {l_bit}, r_bit: {r_bit}')

            if l_bit ^ r_bit:
                n = n ^ 1 << l
                n = n ^ 1 << r

            r += 1
            l -= 1

        return n

    def reverse_bits_int2(self, n:int) -> int:
        ans = 0
        for i in range(8):
            ans = ans << 1 | n >> i & 1

        return ans

sol = Solution()
# inp = '01100010'
# out = sol.reverse_bits_str2(inp)
# print(f'inp: {inp}')
# print(f'out: {out}')

inp = 98
out = sol.reverse_bits_int(inp)
print(f'inp: {inp}') # '01100010' 98
print(f'out: {out}') # '01000110' 70
