class Solution {
public:
    bool isPossible(int row, int col, int n, const vector<string>& board) {
        int copR = row;
        int copC = col;

        // Check Upper Left Diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--; col--;
        }

        // Check Row (to the left)
        row = copR; col = copC;
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        // Check Lower Left Diagonal
        row = copR; col = copC;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++; col--;
        }

        return true;
    }

    // Changed parameter from 'row' to 'col'
    int recur(int col, int n, vector<string>& board) {
        // Base case: If we successfully placed queens in all columns (0 to n-1)
        if (col == n) {
            return 1;
        }

        int count = 0;
        // Loop through all rows for the current column
        for (int row = 0; row < n; row++) {
            if (isPossible(row, col, n, board)) {
                board[row][col] = 'Q';
                
                // Sum the results of all valid placements in this branch
                count += recur(col + 1, n, board);
                
                // Backtrack
                board[row][col] = '.';
            }
        }
        return count;
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        // Start filling from column 0
        return recur(0, n, board);
    }
};
