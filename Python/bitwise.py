class Solution:
    def set_bit(self, n: int, pos: int) -> int:
        n = n | 1 << pos
        return n

    def clear_bit(self, n: int, pos: int) -> int:
        n = n & ~(1 << pos)
        return n

    def toggle_bit(self, n:int, pos: int) -> int:
        n = n ^ 1 << pos
        return n

    def check_bit(self, n: int, pos: int) -> int:
        bit = n & 1 << pos
        return bit

    def change_bit(self, n: int, pos: int, v: int) -> int:
        print(f'v: {v}, {v:08b} << {pos}: {v << pos:08b}')
        n = (n & ~(1 << pos)) | (v << pos)
        return n

'''
* set a bit
* clear a bit
* toggle a bit
* check a bit
* change a bit
'''
# 100 -> 01100100 -> set a bit at pos:1 -> 01100110
sol = Solution()
print(sol.set_bit(100, 1))
print(sol.clear_bit(100, 2))
print(sol.toggle_bit(100, 3))
print(sol.check_bit(100, 2))
print(sol.change_bit(100, 7, 1))
