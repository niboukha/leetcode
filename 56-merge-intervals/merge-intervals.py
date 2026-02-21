class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        intervals.sort(key=lambda x: x[0])
        merged_intervals = []

        i = 0
        while i < len(intervals):
            start, end = intervals[i]

            while i + 1 < len(intervals) and intervals[i + 1][0] >= start and intervals[i + 1][0] <= end:
                end = max(end, intervals[i + 1][1])
                i += 1
                
            merged_intervals.append([start, end])
            i += 1

        return merged_intervals
