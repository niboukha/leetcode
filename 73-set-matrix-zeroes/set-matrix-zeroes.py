class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        row = [0] * len(matrix)
        col = [0] * len(matrix[0])
        
        for i in range(0, len(matrix)):
            for j in range(0, len(matrix[i])):
                if matrix[i][j] == 0:
                    col[j] = 1
                    row[i] = 1

        for i,_ in enumerate(row):
            if row[i] == 1:
               matrix[i] = [0] * len(matrix[i])
        for j,_ in enumerate(col):
            if col[j] == 1:
                for row in matrix:
                    row[j] = 0
            


#    1 0 0 1 
# 1  0 1 2 0 0000
# 0  3 4 5 2 0450
# 0  1 3 1 5 0310

# col[0] row[3]
# col[1] row[0]
# col[1] row[3]


