class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        for layer in range(n // 2):
            left = layer
            right = n - 1 - layer

            for i in range(right - left):
                top = left
                bottom = right

                temp = matrix[top][left + i]

                # bottom-left -> top-left
                matrix[top][left + i] = matrix[bottom - i][left]

                # bottom-right -> bottom-left
                matrix[bottom - i][left] = matrix[bottom][right - i]

                # top-right -> bottom-right
                matrix[bottom][right - i] = matrix[top + i][right]

                # temp (top-left) -> top-right
                matrix[top + i][right] = temp






        