class Solution:
    def convertToTitle(self, num: int) -> str:
        ans = ""
        while num > 0:
            num -= 1
            ans = chr(num % 26 + ord('A')) + ans
            num //= 26

        return ans
        


