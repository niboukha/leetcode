class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        sub = s * 2
        return (s in sub[1:-1])
            
        
  