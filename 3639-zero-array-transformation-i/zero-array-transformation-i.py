class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:

        diff = [0] * (len(nums) + 1)
        for i in queries:
            diff[i[0]] += 1
            diff[i[1] + 1] -= 1
        
        i = 1
        nums[0] -= diff[0]
        while i < len(nums):
            diff[i] += diff[i - 1]
            nums[i] -= diff[i]
            i += 1

        return all(val <= 0 for val in nums)

