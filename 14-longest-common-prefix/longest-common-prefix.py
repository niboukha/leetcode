class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        lcp = strs[0]
        for s in strs[1:]:
            while not s.startswith(lcp):
                lcp = lcp[:-1]
                if not lcp:
                    return ""
        return lcp