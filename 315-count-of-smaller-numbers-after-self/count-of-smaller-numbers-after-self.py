class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:

        ans = [0] * len(nums)
        def merge(nums, l, m, r):
            # print(r - l + 1)
            temp = [0] * (r - l + 1)
            i, j, k = l, m + 1, 0
            # print(nums[i:m], nums[j:r], i, j)
            while i <= m and j <= r:
                # print("processing: ", ans)
                # print(nums[i][0], " -- ", nums[j][0])
                if nums[i][0] > nums[j][0]:
                    # print("-------->", nums[i])
                    ans[nums[i][1]] += r - j + 1
                    temp[k] = nums[i]
                    i += 1
                else:
                    temp[k] = nums[j]
                    j += 1
                k += 1
            
            while i <= m:
                temp[k] = nums[i]
                i += 1
                k += 1
            while j <= r:
                temp[k] = nums[j]
                j += 1
                k += 1

            i = l
            while i <= r:
                nums[i] = temp[i - l]
                i += 1
            # print("ans ---> ", ans)
            # print("nums ---> ", nums)

        def mergeSort(nums, l, r):
            if l < r:
                m = (l + r) // 2
                mergeSort(nums, l, m)
                mergeSort(nums, m + 1, r)
                merge(nums, l, m, r)

        arr = []
        for i, n in enumerate(nums):
            arr.append((n, i))

        mergeSort(arr, 0, len(arr) - 1)

        return ans
