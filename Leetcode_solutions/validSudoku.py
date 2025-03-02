class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        cols  = collections.defaultdict(set)
        rows = collections.defaultdict(set)
        squares = collections.defaultdict(set) # key = (row/3,col/3)

        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue
                if (
                    board[r][c] in rows[r] or
                    board[r][c] in cols[c] or
                    board[r][c] in squares[(r // 3,c // 3)]
                 ):
                    return False
                cols[c].add(board[r][c])
                rows[r].add(board[r][c])
                squares[ (r // 3),(c // 3)].add(board[r][c])

        return True

# for 9*9 sudoku board, we need to check each row, column and 3*3 square
# Time complexity: O(1) as the board is always 9*9 , acutal complexity is O(n^2)
# Space complexity: O(1) as the board is always 9*9,  acutal complexity is O(n^2)