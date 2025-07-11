class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1

        while l <= r:
            m = (l + r) // 2
            if m == r or (nums[m] > nums[m - 1] and nums[m] > nums[m + 1]):
                return m
                
            if m == r or nums[m] <= nums[m + 1]:
                l = m + 1
            else:
                r = m - 1
        
        return 0
