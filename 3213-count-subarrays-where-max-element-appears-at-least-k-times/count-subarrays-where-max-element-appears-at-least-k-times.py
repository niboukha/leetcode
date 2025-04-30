class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        l = r = 0
        res = 0

        n = max(nums)
        m = 0
        # print(len(nums))
        while r < len(nums):
            if nums[r] == n:
                m += 1
            while m == k:
                if nums[l] == n:
                    m -= 1
                l += 1
            res += l
            r += 1

        return res
