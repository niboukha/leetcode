class MinStack:

    def __init__(self):
        self.MinStack = []

    def push(self, val: int) -> None:

        minVal = val
        if self.MinStack:
            minVal = min(val, self.MinStack[-1][1])

        self.MinStack.append((val, minVal))

    def pop(self) -> None:

        if self.MinStack:
            self.MinStack.pop()

    def top(self) -> int:

        if self.MinStack:
            return self.MinStack[-1][0]

        return -1

    def getMin(self) -> int:

        if self.MinStack:
            return self.MinStack[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()