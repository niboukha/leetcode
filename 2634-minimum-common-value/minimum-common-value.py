class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:

        hash = set(nums1)
        for n in nums2:
            if n in hash:
                return n
        return -1