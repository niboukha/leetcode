class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        m = defaultdict(int)
        
        for num in nums:
            m[num] += 1
            if m[num] == 2:
                return True
        
        return False
