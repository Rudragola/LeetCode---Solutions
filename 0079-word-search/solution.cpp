class Solution {
public:
    bool recur(int i, int j, int cnt, vector<vector<char>>& board,
               string& word) {
        if (cnt == word.length()) {
            return true;
        }
        int n = board.size();
        int m = board[0].size();
        if (i < 0 || j < 0 || i > n-1 || j > m-1 || board[i][j] != word[cnt]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = recur(i+1,j,cnt+1,board,word)||
                     recur(i-1,j,cnt+1,board,word)||
                     recur(i,j+1,cnt+1,board,word)||
                     recur(i,j-1,cnt+1,board,word);

        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (recur(i,j,0,board,word))
                    return true;
            }
        }
        return false;
    }
};
