class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        m = defaultdict(int)
        l = 0
        r = 0

        res = 0
        while r < len(s):
            print(r)
            m[s[r]] += 1

            while m[s[r]] > 1:
                m[s[l]] -= 1
                l += 1
            
            res = max(res, r - l + 1)

            r += 1
        
        return res

