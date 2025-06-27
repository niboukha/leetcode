class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        
        res = [-1] * 1000

        indices = [i for i, n in enumerate(nums) if n == key]

        j = 0
        for i, n in enumerate(indices):
            j = 0
            while j < len(nums):
                if abs(n - j) <= k:
                    res[j] = j
                j += 1


        return list(filter(lambda x: x != -1, res))
