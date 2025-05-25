class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        count = Counter(words)
        ans = 0
        m = 0
        
        for word, c in count.most_common():

            if word[0] != word[1]:
                ans += (min(c, count[word[::-1]]) * 2)
            else:
                if c % 2 != 0:
                    if m == 0:
                        m = max(m, c)
                        ans += m * 2
                    else:
                        ans += (c - 1) * 2
                else:
                    ans += c * 2
        return ans

# ll ll
# lb lb lb bl lb
# bb bb bb
# bx xb bx bx
# xx xx xx
# lx lx xl

# ll xl bx xx lb bb bb bb bl xx xb lx ll

# lxxxlllbbbbbbbblllxxxl