class Solution {
public:
    bool isPossible(int row, int col, int n, vector<string>& cur,
                    vector<vector<string>>& ans) {
        int copR = row;
        int copC = col;

        // upper Left diagonal
        while (row >= 0 && col >= 0) {
            if (cur[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // in row
        row = copR;
        col = copC;
        while (col >= 0) {
            if (cur[row][col] == 'Q')
                return false;
            col--;
        }

        // lower left diagonal
        row = copR;
        col = copC;
        while (row < n && col >= 0) {
            if (cur[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    void recur(int col, int n, vector<vector<string>>& ans,
               vector<string>& cur) {
        if (col == n) {
            ans.push_back(cur);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isPossible(row, col, n, cur, ans)) {
                cur[row][col] = 'Q';
                recur(col + 1, n, ans, cur);
                cur[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));
        recur(0, n, ans, cur);
        return ans;
    }
};
