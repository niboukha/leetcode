class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        res = 0
        hash = [0] * 100
        
        for dominoe in dominoes:
            i, j = dominoe[0], dominoe[1]
            num = i * 10 + j if i < j else j * 10 + i
            res += hash[num]
            hash[num] += 1
            
        return res

# 12
# 12
# 34
# 56

# [[1,2],[2,1],[3,4],[6,5],[5,6],[4,3]]

# 12
# 12
# 34
# 56
# 56
# 34
