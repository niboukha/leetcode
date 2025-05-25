class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        ans = 0
        ans1 = 0
        count = Counter(words)
        arr = []
        sim = []
        m = 0
        # print(count)
        for word, c in count.most_common():

            if word[0] != word[1]:
                ans += (min(c, count[word[::-1]]) * 2)
            else:
                if c % 2 != 0:
                    if m == 0:
                        # print("++", word, c)
                        m = max(m, c)
                        ans += m * 2
                    else:
                        # print("---", word, c)
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