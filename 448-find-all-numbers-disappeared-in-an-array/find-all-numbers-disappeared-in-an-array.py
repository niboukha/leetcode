class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:

        # count = [0] * len(nums)
        # for i, n in enumerate(nums):
        #     count[nums[i] - 1] += 1
        # return [i + 1 for i, c in enumerate(count) if c == 0]


        for i in range(len(nums)):
            while nums[i] != nums[nums[i] - 1]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        return [i + 1 for i in range(len(nums)) if nums[i] != i + 1]

