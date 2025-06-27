class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        l = 1
        r = max(piles)
        res = r

        while l <= r:

            k = (r + l) // 2
            speed = sum(ceil(p / k) for p in piles)

            if speed <= h:
                res = k
                r = k - 1
            else:
                l = k + 1
                

        return res
