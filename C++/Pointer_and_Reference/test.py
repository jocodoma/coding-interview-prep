# # danger - garden (anagram)

# # 0 -> a, ..., 25 -> z
# # input: str1, str2

# # class Solution:
# #     def check_anagram(self, str1: str, str2: str) -> bool:
# #         if len(str1) != len(str2):
# #             return False

# #         table1 = {}
# #         table2 = {}
# #         for i in range(len(str1)):
# #             key = str1[i]
# #             if key in table1:
# #                 table1[key] += 1
# #             else:
# #                 table1[key] = 1

# #         for i in range(len(str2)):
# #             key = str2[i]
# #             if key in table2:
# #                 table2[key] += 1
# #             else:
# #                 table2[key] = 1

# #         for key in table1:
# #             if key not in table2 or table1[key] != table2[key]:
# #                 return False

# #         return True

# # sol = Solution()
# # print(sol.check_anagram('danger', 'garden'))




