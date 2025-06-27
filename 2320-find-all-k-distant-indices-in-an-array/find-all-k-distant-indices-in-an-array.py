class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        
        res = set()
        for i, num in enumerate(nums):
            if num == key:
                l = i
                r = i
                while l >= 0 and abs(l - i) <= k:
                    res.add(l)
                    l -= 1
                while r < len(nums) and abs(r - i) <= k:
                    res.add(r)
                    r += 1

        return list(res)
