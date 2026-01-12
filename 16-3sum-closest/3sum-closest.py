class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        print(nums)
        n = len(nums)
        ans = nums[0] + nums[1] + nums[2]
        i = 0
        # print(i, n-3)
        while i <= n - 3:
            l , r = i + 1, n - 1
            while l < r:
                sum = nums[i] + nums[l] + nums[r]
                # print(i, l, r, sum, ans)
                # print(nums[i], nums[l], nums[r])
                if abs(target - sum) <= abs(target - ans):
                    ans = sum
                if sum < target:
                    l += 1
                else:
                    r -= 1
            i += 1

        return ans            
