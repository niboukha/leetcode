class MyHashMap:

    def __init__(self):
        self.mapArray = [-1] * 1000001

    def put(self, key: int, value: int) -> None:
        self.mapArray[key] = value

    def get(self, key: int) -> int:
        return self.mapArray[key]

    def remove(self, key: int) -> None:
        self.mapArray[key] = -1


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)