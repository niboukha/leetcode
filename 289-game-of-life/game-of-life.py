class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Modify board in-place using state encoding.
        
        """
        rows, cols = len(board), len(board[0])

        directions = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1),           (0, 1),
            (1, -1),  (1, 0),  (1, 1)
        ]

        def count_neighbors(r: int, c: int) -> int:
            count = 0
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols:
                    if board[nr][nc] == 1 or board[nr][nc] == 3:
                        count += 1
            return count
        
        # First pass: apply transitions
        for r in range(rows):
            for c in range(cols):
                live_neighbors = count_neighbors(r, c)
                if board[r][c] == 1 and live_neighbors in [2,3]:
                    board[r][c] = 3  # live -> live
                elif board[r][c] == 0 and live_neighbors == 3:
                    board[r][c] = 2  # dead -> live
                    
        # Second pass: finalize states
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == 1:
                    board[r][c] = 0
                elif board[r][c] in [2,3]:
                    board[r][c] = 1