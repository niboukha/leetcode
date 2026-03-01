class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        directions = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1),           (0, 1),
            (1, -1),  (1, 0),  (1, 1)
        ]

        rows = len(board)
        cols = len(board[0])

        for r in range(rows):
            for c in range(cols):
                count = 0
                for dr, dc in directions:
                    nr = r + dr
                    nc = c + dc

                    if 0 <= nr < rows and 0 <= nc < cols:
                        if board[nr][nc] == 1 or board[nr][nc] == 3:
                            count += 1
                if board[r][c] == 1 and count in [2,3]:
                    board[r][c] = 3
                elif board[r][c] == 0 and count == 3:
                    board[r][c] = 2
                        
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == 1:
                    board[r][c] = 0
                elif board[r][c] in [2,3]:
                    board[r][c] = 1
                    