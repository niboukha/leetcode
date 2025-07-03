class Solution:
    def kthCharacter(self, k: int) -> str:
        
        word = "a"
        while k > len(word):
            l = len(word)
            for i in range(l):
                c = chr(ord('a') + (ord(word[i]) - ord('a') + 1) % 26)
                word += c

        return word[k - 1]



# a -> b
# ab => a->b b->c

# abbc
# abbcbccd