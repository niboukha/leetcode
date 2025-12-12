class Solution:
    def mySqrt(self, x: int) -> int:
        i, j = 0, x
        while i <= j:
            m = (i + j) // 2
            if m * m == x:
                return m
            if m * m > x:
                j = m - 1
            else:
                i = m + 1
        return i - 1


