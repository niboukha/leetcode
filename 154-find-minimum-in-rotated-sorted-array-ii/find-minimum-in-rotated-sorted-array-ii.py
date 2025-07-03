class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        ans = 5000
        while l <= r:
            mid = (r + l) // 2 
            ans = min(ans, nums[mid])
            if nums[mid] > nums[r]:
                l = mid + 1
            elif nums[mid] < nums[r]:
                r = mid - 1
            else:
                r -= 1

        return ans