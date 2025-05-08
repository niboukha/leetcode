class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        ans = ""

        i = l = r = 0
        while i < len(s):
            if i == 0:
                ans = s[i]
            # print((r - l) % 2, l ,i, r)
            l = r = i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                # print(s[l:r + 1])
                if len(ans) <= len(s[l: r+1]):
                    ans = s[l: r+1]
                r += 1
                l -= 1
            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                # print(s[l:r + 1])
                if len(ans) <= len(s[l: r+1]):
                    ans = s[l: r+1]
                r += 1
                l -= 1    
            i += 1

        return ans
                