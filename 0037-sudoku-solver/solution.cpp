class Solution {
public:

    bool isSafe(vector<vector<char>>& board , int row , int col , int dig){
        //horizontal
        for(int i = 0;i<9;i++){
            if(board[row][i] == dig){
                return false;
            }
        }

        //vertical
        for(int i = 0;i<9;i++){
            if(board[i][col] == dig){
                return false;
            }
        }

        //in grid
        int srow = (row/3) * 3;
        int scol = (col/3) * 3;
        for(int i = srow;i<=srow+2;i++){
            for(int j = scol;j<=scol+2;j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }
        return true;
    }

    bool  helper(vector<vector<char>>& board , int row , int col){
        //base case
        if(row == 9){
            return true;
        }

        //RECURSION
        //to change the box
        int nextRow = row ,nextCol = col+1;
        if(nextCol == 9){
            nextRow = row +1;
            nextCol = 0;
        }
        //to check if box is empty or not
        if(board[row][col] != '.'){
            return helper(board, nextRow , nextCol);
        }

        for(char dig = '1';dig<='9';dig++){
            if(isSafe(board , row , col , dig)){
                board[row][col] = dig;
               if(helper(board , nextRow ,nextCol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};
