class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = []
        
        n = len(intervals)
        i = 0
        
        # Step 1: Add intervals that end before the new interval starts
        # These cannot overlap with newInterval at all.
        while i < n and intervals[i][1] < newInterval[0]:
            ans.append(intervals[i])
            i += 1
        
        # Step 2: Merge overlapping intervals with newInterval
        # Continue while there is overlap
        while i < n and intervals[i][0] <= newInterval[1]:
            # Update start to the smallest start point
            newInterval[0] = min(newInterval[0], intervals[i][0])
            # Update end to the largest end point
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1
        
        # Now the newInterval has been merged with all overlapping ones
        ans.append(newInterval)
        
        # Step 3: Add the remaining intervals
        # All leftover intervals start after newInterval ends
        while i < n:
            ans.append(intervals[i])
            i += 1
        
        return ans