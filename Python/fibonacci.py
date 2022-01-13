class Solution:
    def fibonacci(self, n: int) -> int:
        # return self.__recursiveMethod(n)
        # return self.__iterativeDynamicProgramming(n)
        return self.__iterativeDP2(n)

    # time complexity: O(2^n), space complexity: O(n)
    def __recursiveMethod(self, n: int) -> int:
        if n < 0:
            print('Incorrect input')

        if n == 0:
            return 0
        elif n == 1:
            return 1
        else:
            return self.__recursiveMethod(n-1) + self.__recursiveMethod(n-2)

    # time complexity: O(n), space complexity: O(n)
    def __iterativeDynamicProgramming(self, n: int) -> int:
        if n < 0:
            print('Incorrect input')

        f = [0,1]
        for i in range(2, n+1):
            f.append(f[i-1] + f[i-2])

        return f[n]

    # time complexity: O(n), space complexity: O(1)
    def __iterativeDP2(self, n: int) -> int:
        if n < 0:
            print('Incorrect input')

        a = 0
        b = 1

        if n == 0:
            return a

        if n == 1:
            return b

        for i in range(2, n+1):
            c = a + b
            a = b
            b = c

        return b

for i in range(0, 15):
    print(Solution().fibonacci(i))
