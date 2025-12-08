class TimeMap:

    def __init__(self):
        self.timeMap = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.timeMap[key].append([value, timestamp])
        
    def get(self, key: str, timestamp: int) -> str:
        ans = ""
        pairs = self.timeMap[key]

        left, right = 0, len(pairs) - 1
        while left <= right:
            m = (left + right) // 2
            if pairs[m][1] <= timestamp:
                ans = pairs[m][0]
            if pairs[m][1] > timestamp:
                right = m - 1
            else:
                left = m + 1
        
        return ans


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)



# curr = timestamp >= prev

# val = 7

# 1 4 6 7 8


