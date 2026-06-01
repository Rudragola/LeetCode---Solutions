class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curSum =0;
        int maxSum =nums[0];
        for(int i =0;i<n;i++){
            curSum += nums[i];

            maxSum = max(curSum ,maxSum);

            if(curSum <0){
                curSum = 0;
            }

        }
        return maxSum;
    }
};
