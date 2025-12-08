class TimeMap:

    def __init__(self):
        self.timeMap = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.timeMap[key].append((timestamp, value))
        
    def get(self, key: str, timestamp: int) -> str:
        timestamps = self.timeMap[key]
        prev = bisect_right(timestamps, timestamp, key=lambda p: p[0]) - 1

        if prev == -1: return ""
        return timestamps[prev][1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)



# curr = timestamp >= prev

# val = 7

# 1 4 6 7 8


