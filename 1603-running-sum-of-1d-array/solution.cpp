class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        vector<int> ans;

        for(int i = 0;i<n;i++){
            cur+=nums[i];
            ans.push_back(cur);
        }
        return ans;
    }
};
