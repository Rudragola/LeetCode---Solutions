class Solution {
public:
    vector<vector<int>> ans;
    void recur(int i ,vector<int>& nums, int tar , int curr , vector<int>& cur){
        if(curr == tar){
            ans.push_back(cur);
            return;
        } 

        if(i == nums.size())  return;
        if(nums[i] + curr <= tar){
            cur.push_back(nums[i]);
            recur(i,nums,tar,curr+nums[i],cur);
            cur.pop_back();
        }

        recur(i+1,nums,tar,curr,cur);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        vector<int> cur;
        recur(0,nums,tar,0,cur);
        return ans;
    }
};
