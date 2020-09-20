class Solution:
    def isValid(self, s: str) -> bool:
        dict = {
            "}" : "{",
            "]" : "[",
            ")" : "("
        }
        pStack = []
        for c in s:
            if c in dict.values():
                pStack.append(c)
            else:
                if not pStack or dict[c] != pStack.pop():
                    return False
        return not pStack;

print(Solution().isValid('(){([])}'))
# True

print(Solution().isValid('(){(['))
# False
