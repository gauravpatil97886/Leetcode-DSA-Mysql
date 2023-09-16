class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def is_valid(num, row, col):
            for i in range(9):
                if board[i][col] == num or board[row][i] == num:
                    return False
            subgrid_row, subgrid_col = 3 * (row // 3), 3 * (col // 3)
            for i in range(subgrid_row, subgrid_row + 3):
                for j in range(subgrid_col, subgrid_col + 3):
                    if board[i][j] == num:
                        return False
            return True
        
        def backtrack():
            for row in range(9):
                for col in range(9):
                    if board[row][col] == ".":
                        for num in map(str, range(1, 10)):
                            if is_valid(num, row, col):
                                board[row][col] = num
                                if backtrack():
                                    return True
                                board[row][col] = "."
                        return False
            return True

        backtrack()
