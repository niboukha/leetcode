class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        
        ans = set()
        j = 0
        
        for i, num in enumerate(nums):
            if num == key:
                if i - k > 0:
                    j = i - k
                while j <= i + k and j < len(nums):
                    ans.add(j)
                    j += 1 

        return list(ans)
