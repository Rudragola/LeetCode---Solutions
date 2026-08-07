class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curSum = 0;
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            curSum += nums[i];
            ans = max(ans , curSum);
            if(curSum < 0){
                curSum = 0;
            }
        }
        return ans;
    }
};
