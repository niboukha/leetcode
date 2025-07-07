class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        counts1 = Counter(nums1)
        counts2 = Counter(nums2)
        ans = []

        for n, c in counts1.items():
            if n in counts2:
                ans += [n] * min(c, counts2[n])
        
        return ans