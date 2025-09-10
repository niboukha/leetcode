class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        ans = []

        for n, _ in count.most_common():
            if k == 0:
                break
            ans.append(n)
            k -= 1

        return ans    