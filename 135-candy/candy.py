class Solution:
    def candy(self, ratings: List[int]) -> int:
        arr = [1] * len(ratings)

        l = 0
        r = 1

        while r < len(ratings):
            # print(arr[r], arr[l])
            if ratings[r] > ratings[l]:
                arr[r] = arr[l] + 1
            r += 1
            l += 1
        # print(arr)
        
        r = len(ratings) - 1
        l = r - 1

        while r > 0:
            # print(arr)
            # print(arr[r], arr[l])
            if ratings[l] > ratings[r] and arr[l] <= arr[r]:
                arr[l] = arr[r] + 1
            r -= 1
            l -= 1

        # print(arr)

        return sum(arr)

# l r 
# 6 2
# 6 > 2 
# but check arr

# 5 6
# do nothing
# 1 1 1 1 1
# 1 1 1 2 1

# r less l

# 5 4 3 5 6 2
# 1 1 1 1 1 1

# ->
# 5 ? pass
# 5 < 4 ? pass
# 4 < 3 ? pass 
# 3 < 5 ? 2
# 5 < 6 ? 3
# 6 < 2 ? pass

# 1 1 1 2 3 1

# <-

# 2 ? pass
# 6 < 2 ? pass
# 5 < 6 ? pass 
# 3 < 5 ? pass
# 4 < 3 ? 2
# 5 < 4 ? 3

# 3 2 1 2 3 1


