class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans ;
        ans.push_back({1});
        int middleElements = 0;

        for(int i = 1 ; i<numRows;i++){
            vector<int> currentRows;
            //first element
            currentRows.push_back(1);

            //middleElements
            for(int j = 1;j<=middleElements;j++){
                int val = ans[i-1][j] + ans[i-1][j-1];
                currentRows.push_back(val);
            }


            //last elements
            currentRows.push_back(1);

            middleElements++;
            ans.push_back(currentRows); 
        }
        return ans;
    }
};
