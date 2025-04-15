class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        res = ""

        for word in words:
            res += word
            if res == s:
                return True
            if len(res) > len(s):
                return False
        
        return False