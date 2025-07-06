class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = nums1
        self.nums2 = nums2
        self.counter1 = Counter(nums1)
        self.counter2 = Counter(nums2)

    def add(self, index: int, val: int) -> None:
        last_val = self.nums2[index]
        self.counter2[last_val] -= 1
        self.nums2[index] += val
        self.counter2[self.nums2[index]] += 1

    def count(self, tot: int) -> int:
        ans = 0
        for n, c in self.counter1.items():
            ans += (c * self.counter2[tot - n])
        return ans

# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)


#  0  1. 2. 3. 4. 5
# [1, 1, 2, 2, 2, 3]
# [1, 4, 5, 2, 5, 4]

# count(7)

# 2,2 3,2 4,2 3,4 4,4 => 2 + 5
# 5,1 5,5 => 3+4


# 1 2
# 2 3
# 3 1

# 1 1
# 2 1
# 4 2
# 5 2


# tot - 2  = ?
# 7 - 2 = 5

# nums2 search 5

# 6
# 3



# for example i have three 2 i need 1 or more 5 to get 7

