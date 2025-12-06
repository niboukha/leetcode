class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        s_i = []
        for idx, (start, end) in enumerate(intervals):
            s_i.append([start, idx])
        s_i.sort()
        ans = [-1] * n
        for idx, (start, end) in enumerate(intervals):
            i, j = 0, n - 1
            val = 2**1000
            while i <= j:
                m = (i + j) // 2
                if end <= s_i[m][0]:
                    j = m - 1
                    if min(val, s_i[m][0]) != val:
                        ans[idx] = s_i[m][1]
                        val = s_i[m][0]
                else:
                    i = m + 1
        return ans




# 1,4 2,3 3,4
# 4 >= ? 2 3 -1
# 2 >= ? 1 3 2
# 3 >= ? 1 2 -1


# 1 2 3 -> 4
# i m j

# 2 < 4
# i = m + 1