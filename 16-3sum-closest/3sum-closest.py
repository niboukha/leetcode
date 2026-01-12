class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        
        nums.sort()
        
        n   = len(nums)
        ans = nums[0] + nums[1] + nums[2]

        for i in range(n - 2):
            l , r = i + 1, n - 1
            while l < r:
                sum = nums[i] + nums[l] + nums[r]
                if abs(target - sum) <= abs(target - ans):
                    ans = sum
                if sum < target:
                    l += 1
                else:
                    r -= 1
            i += 1

        return ans            
