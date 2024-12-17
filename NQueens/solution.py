class Solution: # Python3 solution to the N-Queens problem using backtracking
    def solveNQueens(self, n: int) -> List[List[str]]:
        col = set()
        posDiag = set() # top left -> bottom right (determined by row + column)
        negDiag = set() # top right -> bottom left (determined by row - column)

        res = [] # result for all possible n-queen solutions
        board = [["."] * n for i in range(n)] # initialize the board (nxn)

        # backtrack approach for placing each queen (row-by-row)
        def backtrack(r):
            if r == n: # base case, checks if every single row is completed
                copy = ["".join(row) for row in board] # copy the board since it will be used in subsequent function calls
                res.append(copy) # append the copy of the board to the result
                return

            for c in range(n):
                if c in col or (r + c) in posDiag or (r - c) in negDiag: # if current column or any diagonals are already in use
                    continue # skip that position as it is already occupied 

                col.add(c) # add the column and diagonals to the unable to use list
                posDiag.add(r + c)
                negDiag.add(r - c)
                board[r][c] = "Q" # update the board

                backtrack(r + 1) # move on to the next row

                col.remove(c)
                posDiag.remove(r + c)
                negDiag.remove(r - c)
                board[r][c] = "."

        backtrack(0)
        return res
