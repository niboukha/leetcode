class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        res = 0

        for n in nums:
            if (n >= 10 and n < 100) or (n >= 1000 and n < 10000) or n == 100000:
                res += 1
        return res