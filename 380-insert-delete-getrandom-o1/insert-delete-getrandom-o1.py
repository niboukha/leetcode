class RandomizedSet:

    def __init__(self):
        self.values = [] # A list to store the values
        self.index_map = {} # A dictionary to map value -> index in the list

    def insert(self, val: int) -> bool:
        if val in self.index_map:
            return False

        self.index_map[val] = len(self.values)
        self.values.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.index_map:
            return False

        idx = self.index_map[val] # Get the index of the value to remove
        last_val = self.values[-1] # Move the last element into the removed spot

        self.values[idx] = last_val
        self.index_map[last_val] = idx

        self.values.pop() # Remove the last element
        del self.index_map[val] # Remove val from the index map

        return True

    def getRandom(self) -> int:
        return random.choice(self.values)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()