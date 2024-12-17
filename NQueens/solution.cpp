#include <iostream> // C++ solution to the N-Queens problem using DFS
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);  // used to track columns and diagonals
        dfs(res, board, 0, n, cols, diag1, diag2);
        return res;
    }

private:
    // DFS to explore all possible solutions
      void dfs(vector<vector<string>>& res, vector<string>& board, int row, int n, vector<int>& cols, vector<int>& diag1, vector<int>& diag2) {
      // when a valid placement is found, add it to the solution  
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            // check if the current column or diagonal is already occupied
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) {
                continue;
            }

            // place queen and mark column and diagonals as occupied
            board[row][col] = 'Q';
            cols[col] = 1;
            diag1[row + col] = 1;
            diag2[row - col + n - 1] = 1;

            // recursively try to place queens in the next row
            dfs(res, board, row + 1, n, cols, diag1, diag2);

            // backtrack: remove queen and reset marks
            board[row][col] = '.';
            cols[col] = 0;
            diag1[row + col] = 0;
            diag2[row - col + n - 1] = 0;
        }
    }
};

int main() {
    Solution solution; // board itself for the final output
    string input; // for user input
    int n; // 1 <= n <= 9

    while (true) {
        cout << "Enter an integer: ";
        getline(cin, input);  // get the input as a string in case it is faulty

        // try converting the input string to an integer
        try {
            n = stoi(input);  // convert to integer

            if (num < 1 || num > 9) {
                cout << "Input must be between 1 and 9. Please try again: " << endl;
                continue;  // ask for input again if not in range
            }
            
            break;  // if successful, break
        }
        catch (const invalid_argument& e) {
            // if not (not a valid integer), prompt again
            cout << "Invalid input. Please enter a valid integer: " << endl;
        }
        catch (const out_of_range& e) {
            // if the input number is out of integer range
            cout << "Input is out of range. Please enter a valid integer: " << endl;
        }
    }

    vector<vector<string>> solutions = solution.solveNQueens(n);
    
    // output the solutions
    for (const auto& solution : solutions) { for (const auto& row : solution) { cout << row << endl; } cout << endl; }
    return 0;
}
