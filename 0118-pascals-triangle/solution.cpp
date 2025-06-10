class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans = {};
        ans.push_back({1});
        int middleElement = 0;

        
        for(int i =1;i<numRows;i++){
            
            vector<int> currentRow;
            //first element 1
            currentRow.push_back(1);
            
            //middle elements
            for(int j = 1;j<=middleElement;j++){
                int val = ans[i-1][j] + ans[i-1][j-1];
                currentRow.push_back(val);
            }

            //last element
            currentRow.push_back(1);

            middleElement++;
            ans.push_back(currentRow);
        }
        return ans;
        
    }
};
