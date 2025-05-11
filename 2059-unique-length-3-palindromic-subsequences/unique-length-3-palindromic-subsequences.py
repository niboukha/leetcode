class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        
        # letters = Counter(s)
        # left = set()
        # sub = set()

        # for m in range(len(s)):
        #     letters[s[m]] -= 1

        #     if letters[s[m]] == 0:
        #         letters.pop(s[m])
            
        #     for l in left:
        #         if l in letters:
        #             sub.add(l + s[m] + l)

        #     left.add(s[m])
        
        # return len(sub)

        res = 0
        for c in set(s):
            start, end = s.find(c), s.rfind(c)

            if start + 1 < end:
                res += len(set(s[start + 1: end]))
            
        return res