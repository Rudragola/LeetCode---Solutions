class Solution {
public:
    bool isPossible(char k, vector<vector<char>>& board, int r, int c) {
        int copR = r;
        int copC = c;
        // check in row
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == k) {
                return false;
            }
        }

        // check in col
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == k) {
                return false;
            }
        }

        int srow = 3 * (r / 3);
        int scol = 3 * (c / 3);

        // check in 3X3 grid
        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == k) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isPossible(k, board, i, j)) {
                            board[i][j] = k;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
