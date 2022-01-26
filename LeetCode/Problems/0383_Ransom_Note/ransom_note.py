from collections import defaultdict

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # return self.__brute_force(ransomNote, magazine)
        return self.__hash_map(ransomNote, magazine)

    # n is the size of ransomNote, m is the size of magazine
    # time complexity: O(n*m), space complexity: O(m)
    def __brute_force(self, ransomNote: str, magazine: str) -> bool:
        magazine_list = list(magazine)
        for letter in ransomNote:
            if letter in magazine_list:
                idx = magazine_list.index(letter)
                magazine_list[idx] = ''
            else:
                return False
        return True

    # time complexity: O(n+m), space complexity: O(m)
    def __hash_map(self, ransomNote: str, magazine: str) -> bool:
        return self.__hash_mapv1
        # return self.__hash_mapv2

    def __hash_mapv1(self, ransomNote: str, magazine: str) -> bool:
        table = {}
        for letter in magazine:
            if letter in table:
                table[letter] += 1
            else:
                table[letter] = 0

        for letter in ransomNote:
            if letter in table:
                table[letter] -= 1
            if letter not in table or table[letter] < 0:
                return False

        return True

    def __hash_mapv2(self, ransomNote: str, magazine: str) -> bool:
        mag_dict = defaultdict(int)
        for letter in magazine:
            mag_dict[letter] += 1

        for letter in ransomNote:
            mag_dict[letter] -= 1
            if mag_dict[letter] < 0:
                return False

        return True


sol = Solution()
ransomNote = "a"
magazine = "b"
output = sol.canConstruct(ransomNote, magazine)
print(f'ransomNote: {ransomNote}, magazine: {magazine}, output: {output}')

ransomNote = "aa"
magazine = "ab"
output = sol.canConstruct(ransomNote, magazine)
print(f'ransomNote: {ransomNote}, magazine: {magazine}, output: {output}')

ransomNote = "aa"
magazine = "aab"
output = sol.canConstruct(ransomNote, magazine)
print(f'ransomNote: {ransomNote}, magazine: {magazine}, output: {output}')
