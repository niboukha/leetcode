class Solution:

    def findSubPalindrome(self, s: str, l: int, r: int) -> str:

        ans = ""
        while l >= 0 and r < len(s) and s[l] == s[r]:
            ans = max(ans, s[l: r+1], key=len)
            r += 1
            l -= 1
        return ans

    def longestPalindrome(self, s: str) -> str:
        
        ans = ""
        i = l = r = 0
        while i < len(s):
            odd = self.findSubPalindrome(s, i, i)
            even = self.findSubPalindrome(s, i, i + 1)
            ans = max(odd, even, ans, key=len)
            i += 1

        return ans
                