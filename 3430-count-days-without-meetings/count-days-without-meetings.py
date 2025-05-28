class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        
        meetings.sort(key=lambda x: x[0])
        # print(meetings)
        merge = []
        ans = 0

        s = meetings[0][0]
        e = meetings[0][1]
        for i in range(1, len(meetings)):
            # print(s, e, meetings[i][0], meetings[i][1])
            if meetings[i][0] >= s and meetings[i][0] <= e:
                # print("------------")
                e = max(e, meetings[i][1])
            else:
                merge.append([s,e])
                s = meetings[i][0]
                e = meetings[i][1]

        merge.append([s,e])
        print(merge)
        for m in merge:
            ans += (m[1] - m[0] + 1)
        
        return days - ans




# # 2 3 4
# 4 - 2
# 2 3
# # 1 2 3 
# 3 - 1
# 2

