class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        
        exist = set()
        for n in arr:
            if n * 2 in exist or n / 2 in exist:
                return True
            exist.add(n)
        
        return False


