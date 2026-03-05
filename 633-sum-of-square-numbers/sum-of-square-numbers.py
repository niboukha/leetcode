class Solution:
    def judgeSquareSum(self, c: int) -> bool:

        l, r = 0, int(isqrt(c))
        while l <= r:
            a, b = l * l, r * r
            if a + b > c:
                r -= 1
            elif a + b < c:
                l += 1
            else:
                return True

        return False