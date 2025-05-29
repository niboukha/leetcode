class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        
        sub = s + s

        if s in sub[1:-1]:
            return True
        
        return False
            
        
  