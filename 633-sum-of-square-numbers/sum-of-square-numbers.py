class Solution:
    def judgeSquareSum(self, c: int) -> bool:

        hash_set = set()
        for i in range(int(math.isqrt(c)) + 1):
            hash_set.add(i)

        for a in range(int(math.isqrt(c)) + 1):
            if math.sqrt(c - a * a) in hash_set:
                return True
        return False