class Solution:
    def findMedianSortedArrays(self, n1: List[int], n2: List[int]) -> float:
        if len(n1) > len(n2):
            n1, n2 = n2, n1

        total = len(n1) + len(n2)
        half = total // 2
        l, r = 0, len(n1) - 1
        while True:
            m = (l + r) // 2
            m2 = half - m - 2

            n1l = n1[m] if m >= 0 else float("-infinity")
            n2l = n2[m2] if m2 >= 0 else float("-infinity")
            n1r = n1[m + 1] if m + 1 < len(n1) else float("infinity")
            n2r = n2[m2 + 1] if m2 + 1 < len(n2) else float("infinity")

            if n1l <= n2r and n2l <= n1r:
                if total % 2:
                    return min(n2r, n1r)
                return (min(n2r, n1r) + max(n2l, n1l)) / 2
            elif n1l > n2r:
                r = m - 1
            else:
                l = m + 1





