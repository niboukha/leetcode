class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        
        aset = set()
        bset = set()
        cset = set()
        C = list()

        for i, n in enumerate(A):
            aset.add(A[i])
            bset.add(B[i])

            if A[i] == B[i]:
                cset.add(A[i])
            if A[i] in bset:
                cset.add(A[i])
            if B[i] in aset:
                cset.add(B[i])

            C.append(len(cset))
            
        return C