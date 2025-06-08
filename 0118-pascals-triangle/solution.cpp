class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {};
        
        //First element 1
        ans.push_back({1});

        int middleElements = 0;

        for(int i =1;i<numRows;i++){
            vector<int> currentRow = {};

            //first element
            currentRow.push_back(1);

            //middle elements
            for(int j =1;j<=middleElements;j++){
                int element = ans[i-1][j] + ans[i-1][j-1];
                currentRow.push_back(element);
            }

            //last element
            currentRow.push_back(1);
            middleElements++;
            ans.push_back(currentRow);
        }

        return ans;
    }
};
