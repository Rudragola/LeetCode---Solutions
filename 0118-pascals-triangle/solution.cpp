class Solution {
public:
    vector<int> row(int n){
        vector<int> ans;
        long long mul = 1;
        ans.push_back(1);

        for(int i = 1;i<n;i++){
            mul = mul*(n-i);
            mul /= i;
            ans.push_back(mul);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1;i<=numRows;i++){
            ans.push_back(row(i));
        }
        return ans;
    }
};
