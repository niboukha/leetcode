class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        counts = Counter(nums1)
        ans = []

        for n in nums2:
            if counts[n]:
                ans.append(n)
                counts[n] -= 1
        
        return ans