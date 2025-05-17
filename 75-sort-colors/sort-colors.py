class Solution:
    def sortColors(self, nums: List[int]) -> None:
        count = Counter(nums)

        i = 0
        for c in sorted(count.keys()):
            # print(c , count[c], nums[i: i + count[c]])
            nums[i:i + count[c]] = [c] * count[c]
            i += count[c]
        # print(nums)
        