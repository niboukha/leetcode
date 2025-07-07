class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        counter1 = Counter(nums1)
        counter2 = Counter(nums2)
        ans = []

        for n, c in counter1.items():
            if n in counter2:
                ans += [n] * min(c, counter2[n])
        
        return ans