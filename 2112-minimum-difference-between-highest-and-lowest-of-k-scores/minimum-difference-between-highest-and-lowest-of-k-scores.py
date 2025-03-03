class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        res = nums[-1]
        for i, num in enumerate(nums):
            if i + k - 1 < len(nums):
                res = min (res, nums[i + k - 1] - nums[i])
            i += 1
        return res
            
        