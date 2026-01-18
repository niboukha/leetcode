class Solution:
    def balancedString(self, s: str) -> int:
        
        hash = Counter(s)

        n = len(s)
        ans = n
        l, r = 0, 0
        target = n // 4
        while r < n:
            hash[s[r]] -= 1
            while l < n and all(c <= target for c in hash.values()):
                hash[s[l]] += 1
                ans = min(ans, r - l + 1)
                l += 1
            r += 1

        return ans
