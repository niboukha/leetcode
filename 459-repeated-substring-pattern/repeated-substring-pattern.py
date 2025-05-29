class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        sub = s + s
        return (s in sub[1:-1])
            
        
  