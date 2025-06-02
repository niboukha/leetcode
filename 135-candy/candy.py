class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)

        arr = [1] * n

        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                arr[i] = arr[i - 1] + 1
            
        for i in range(n - 1, 0, -1):
            if ratings[i - 1] > ratings[i]:
                arr[i - 1] = max(arr[i] + 1, arr[i - 1])
        
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


