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

        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }

        subSets(i+1,ans,nums,cur);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        subSets(0,ans,nums,cur);
        return ans;
    }
};
