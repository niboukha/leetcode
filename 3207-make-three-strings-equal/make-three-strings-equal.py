class Solution:
    def findMinimumOperations(self, s1: str, s2: str, s3: str) -> int:

        n = min(len(s1), len(s2), len(s3))
        ans = (len(s1) - n) + (len(s2) - n) + (len(s3) - n)
        
        while n > 0:
            if s1[0: n] == s2[0: n] == s3[0: n]:
                return ans
            ans += 3
            n -= 1
        return -1

