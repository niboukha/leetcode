class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:

        res = 0
        tar = 0
        left = right = 0
        while left < len(nums):
            # print(left , right, tar)
            if right < len(nums) and k > ((tar + nums[right]) * (right - left + 1)):
                tar += nums[right]
                right += 1
            else:
                res += (right - left)
                tar -= nums[left]
                left += 1
        
        return res