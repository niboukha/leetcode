class Solution:
    def possibleStringCount(self, word: str) -> int:
        
        ans = len(word)
        for i in range(1, len(word)):
            if word[i] != word[i - 1]:
                ans -= 1
        return ans



# a b b c c c c

# a b b c c c c
# 1 1 2 1 2 3 4

# 1 1 3

# a b c d
# 1 1 1 1

# e r e
# 1 1 1
