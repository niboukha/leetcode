class Solution:
    def possibleStringCount(self, word: str) -> int:
        
        ans = 0
        i = 0
        sub = ""
        while i < len(word):
            # print(sub, "-",word[i], i, "-", ans)
            sub += word[i]
            if sub.count(word[i]) == len(sub):
                ans += 1
            else:
                sub = sub[len(sub) - 1:]
                # print("sub: ", sub)
            i += 1

        return ans



# a b b c c c c

# a b b c c c c
# 1 1 2 1 2 3 4

# 1 1 3

# a b c d
# 1 1 1 1

# e r e
# 1 1 1
