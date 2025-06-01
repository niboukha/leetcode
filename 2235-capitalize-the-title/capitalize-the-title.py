class Solution:
    def capitalizeTitle(self, title: str) -> str:
        title = title.lower()
        words = title.split(' ')
        ans = ""

        for word in words:
            if len(word) > 2:
                word = word.title()
            ans += word + ' '
        
        return ans[0:len(ans) - 1]