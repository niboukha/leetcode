class Solution(object):
    def minimumMoves(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        res = 0
        while i < len(s):
            if s[i] != 'X':
                i += 1
            elif 'X' in s[i:i + 3]:
                res += 1
                i += 3

        return res
        