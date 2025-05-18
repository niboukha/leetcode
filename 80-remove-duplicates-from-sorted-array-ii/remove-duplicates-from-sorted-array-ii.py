class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = Counter(nums)
        k = 0

        for c in sorted(count.keys()):
            
            nums[k: k + count[c]] = [c] * min(count[c], 2)
            k += min(count[c], 2)

        return k
                



