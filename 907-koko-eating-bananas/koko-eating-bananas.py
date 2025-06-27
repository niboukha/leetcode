class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        l = 1
        r = max(piles)
        k = math.ceil(max(piles) / 2)
        speed = 0
        res = float('inf')

        while l <= r:

            speed = 0
            for p in piles:
                speed += math.ceil(p / k)

            if speed <= h:
                res = min(k, res)
                r = k - 1
                k = math.ceil(r / 2)
            else:
                l = k + 1
                k = math.ceil((r + l) / 2)
                

        return res
