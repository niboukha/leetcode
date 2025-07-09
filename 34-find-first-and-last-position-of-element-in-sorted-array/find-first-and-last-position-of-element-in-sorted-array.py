class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l = 0
        r = len(nums) - 1
        x = -1
        y = -1
        while l <= r:
            m = (l + r) // 2
            if nums[m] <= target:
                if nums[m] == target:
                    y = m
                l = m + 1
            else:
                r = m - 1
        l = 0
        r = len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] >= target:
                if nums[m] == target:
                    x = m
                r = m - 1
            else:
                l = m + 1
        
        return [x, y]


# 5 6 7 7 8 8 8
# l.      l m r
          




