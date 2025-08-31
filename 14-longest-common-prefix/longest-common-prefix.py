class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        lcp = strs[0]
        for s in strs:
            if len(lcp) > len(s):
                lcp = lcp[0: len(s)]

            for i in range(len(lcp)):
                if s[i] != lcp[i]:
                    lcp = lcp[0: i]
                    break
    
        return lcp