/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    // helper function for checking if a given cell is valid for a specific number
    const isValid = (board, row, col, num) => {
        for (let i = 0; i < 9; i++) {
            // check if the number already exists in the current row/column
            if (board[row][i] === num || board[i][col] === num) return false;

            // form the 3x3 grid
            const boxRow = 3 * Math.floor(row / 3) + Math.floor(i / 3);
            const boxCol = 3 * Math.floor(col / 3) + (i % 3);

            // check if the number already exists in the current 3x3 grid
            if (board[boxRow][boxCol] === num) return false;
        }

        return true;
    };

    // backtracking function to solve the board
    const backtrack = () => {
        // traverse the entire sudoku grid
        for (let row = 0; row < 9; row++) {
            for (let col = 0; col < 9; col++) {

                // find the first empty cell
                if (board[row][col] === ".") {

                    // for each empty cell, try inserting 1..9
                    for (let num = 1; num <= 9; num++) {
                        const char = num.toString(); // convert to string

                        // if the current number can be inserted to the specified row/column/grid
                        if (isValid(board, row, col, char)) {
                            board[row][col] = char; // temporarily place the number
                            if (backtrack()) return true; // to resolve recursion
                            board[row][col] = "."; // if no solution is found with the current number, reset the cell
                        }
                    }

                    // if no number can be placed in the current empty cell, backtrack to the previous step
                    return false;
                }
            }
        }

        
        return true;
    };

    // begin the recursive process to fill the board
    backtrack();
};

// solveSudoku(board);
// console.log(board.map(row => row.join(" ")).join("\n"));
