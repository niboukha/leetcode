class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        diff = [0] * (len(nums) + 1)
        for i in queries:
            diff[i[0]] += 1
            diff[i[1] + 1] -= 1

        print(diff)
        
        i = 1
        nums[0] -= diff[0]
        while i < len(nums):
            print(nums[i - 1] , diff[i])
            diff[i] += diff[i - 1]
            nums[i] -= diff[i]
            # nums[i] -= (nums[i - 1] - diff[i])
            i += 1

        print(nums)
        return all(val <= 0 for val in nums)

