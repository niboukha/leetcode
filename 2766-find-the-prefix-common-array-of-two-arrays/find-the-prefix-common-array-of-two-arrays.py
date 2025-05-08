class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        
        seen = set()
        C = [0] * len(A)
        count = 0

        for i in range(len(A)):

            if A[i] in seen: count += 1
            else: seen.add(A[i])

            if B[i] in seen: count += 1
            else: seen.add(B[i])

            C[i] = count
            
        return C