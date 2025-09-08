class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge(nums, left, mid, right):
            numsL, numsR = nums[left: mid + 1], nums[mid + 1: right + 1]
            
            i, j, k = 0, 0, left
            while i < len(numsL) and j < len(numsR):
                if numsL[i] <= numsR[j]:
                    nums[k] = numsL[i]
                    i += 1
                else:
                    nums[k] = numsR[j]
                    j += 1
                k += 1
            
            while i < len(numsL):
                nums[k] = numsL[i]
                i += 1
                k += 1
            
            while j < len(numsR):
                nums[k] = numsR[j]
                j += 1
                k += 1
            
        def mergeSort(nums, left, right):
            if left == right:
                return
            mid = (left + right) // 2

            mergeSort(nums, left, mid)
            mergeSort(nums, mid + 1, right)
            merge(nums, left, mid, right)

        mergeSort(nums, 0, len(nums))

        return nums