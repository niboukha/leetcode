class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:

        sumN = 0
        sumM = 0

        for i in range(1, n+1):

            if i % m: sumN += i
            if i % m == 0: sumM += i

        return sumN - sumM
