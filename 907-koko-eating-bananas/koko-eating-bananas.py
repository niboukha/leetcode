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
                # print("k : ", k)
                speed += math.ceil(p / k)

            # print("speed: ",speed)
            if speed <= h:
                res = min(k, res)
                r = k - 1
                # print(r, k, r/2, math.ceil(r/ 2))
                k = math.ceil(r / 2)
            else:
                l = k + 1
                k = int((r + l) / 2)
                # print("up: ",l, k ,r)
                

        return res


# 1 2 3 4 5 6 7 8 9 10 11

# 1 2 3 4 5 6

# 1 2 3 4 5

# 4 5



# l = 4
# r = 5

# 1 11

# 1 6

# 1 3


# 3 / 4 = 0



# 6 / 4 = 2

# 7 / 4 = 2 