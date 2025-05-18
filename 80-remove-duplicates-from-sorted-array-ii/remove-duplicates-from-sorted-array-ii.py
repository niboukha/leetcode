class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = Counter(nums)
        k = 0

        for c in sorted(count.keys()):
            m = min(count[c], 2)
            nums[k: k + count[c]] = [c] * m
            k += m

        return k
                



