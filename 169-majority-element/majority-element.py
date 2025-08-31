class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        count = Counter(nums)
        for n, c in count.items():
            if c > len(nums) / 2:
                return n
        