class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        m = defaultdict(int)
        j = 0

        for i, num in enumerate(nums):
            if i - j > k:
                del m[nums[j]]
                j += 1
            if nums[i] in m:
                return True
            m[nums[i]] += 1
            i += 1
        return False


                
        