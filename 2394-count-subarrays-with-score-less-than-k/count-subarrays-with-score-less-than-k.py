class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:

        res = 0
        sm = 0
        l = r = 0
        score = 0
        while r < len(nums):

            sm += nums[r]
            score = sm * (r - l + 1)
            while score >= k:
                sm -= nums[l]
                l += 1
                score = sm * (r - l + 1)
            res += r - l + 1
            r += 1
        
        return res