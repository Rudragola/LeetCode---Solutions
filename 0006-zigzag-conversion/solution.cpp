class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1){
            return s;
        }

        vector<vector<char>> ans(numRows);

        int rowIndex= 0;
        int turn =0;

        for(int i = 0;i<s.length();i++){

            ans[rowIndex].push_back(s[i]);

            if(turn == 0){
                rowIndex++;
                if(rowIndex == numRows){
                    rowIndex-=2;
                    turn = 1;
                }
            }
            else{
                rowIndex--;
                if(rowIndex == -1){
                    rowIndex+=2;
                    turn = 0;
                }
            }
         
        }
        string answer = "";
        for(int i = 0; i < ans.size(); i++){
            for(char c : ans[i]){
                answer += c;
            }
        }

        return answer; 
     }
};
