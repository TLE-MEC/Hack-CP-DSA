'''
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:
'''


def isValid(board, r, c, cand):

    if any(board[r][j] == cand for j in range(9)):
        return False

    if any(board[i][c] == cand for i in range(9)):

        return False

    br, bc = 3*(r//3), 3*(c//3)
    if any(board[r-r % 3+i//3][c-c % 3+i % 3] == cand for i in range(9)):
        return False
    return True


def solve(board, r, c):

    while board[r][c] != '.':
        c += 1
        if c == 9:
            c, r = 0, r+1
        if r == 9:
            return True

    for k in range(1, 10):
        if isValid(board, r, c, str(k)):
            board[r][c] = str(k)
            if solve(board, r, c):
                return True
    board[r][c] = '.'
    return False


def solveSudoku(board) -> None:
    solve(board, 0, 0)
