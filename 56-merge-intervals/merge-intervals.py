class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        """    
           Sort the intervals by their starting value.
           This ensures that if two intervals overlap, they will be next to
           each other after sorting. Sorting also makes it easy to merge
           in one pass. :contentReference[oaicite:1]{index=1}
        """
        
        intervals.sort(key=lambda x: x[0])
        merged_intervals = []

        i = 0
        while i < len(intervals):
            # Take the start and end of the current interval
            start, end = intervals[i]
            
            # If the next interval starts before or at the current end,
            # they overlap, so update the end to be the maximum.
            # Continue this while we have overlapping intervals.
            while (i + 1 < len(intervals) and
                   intervals[i + 1][0] <= end):
                # If the next interval overlaps,
                # update 'end' to the larger endpoint.
                end = max(end, intervals[i + 1][1])
                i += 1
                
            # After merging all overlaps for this group,
            # append the merged interval.
            merged_intervals.append([start, end])            
            i += 1

        return merged_intervals
