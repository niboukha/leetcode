class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        
        ans = 0
        for i, row in enumerate(grid):
            l, r = 0, len(row) - 1
            while l <= r:
                m = (l + r) // 2
                if row[m] < 0:
                    r = m - 1
                else:
                    l = m + 1
            ans += len(row) - l
            
        return ans

