class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = Counter(nums)
        k = 0

        for c in sorted(count.keys()):
            m = 2 if count[c] > 2 else count[c]
            nums[k: k + count[c]] = [c] * m
            k += m

        return k