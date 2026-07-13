class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void subSets(int i , vector<vector<int>>& ans ,vector<int>& nums,vector<int>& cur ){
        if(i == nums.size()){
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        subSets(i+1,ans,nums,cur);
        cur.pop_back();

        subSets(i+1,ans,nums,cur);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subSets(0,ans,nums,cur);
        return ans;
    }
};
