class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int preSum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int count = 0;
        for(int i = 0;i<n;i++){
            preSum += nums[i];
            count += mpp[preSum - k];
            mpp[preSum]++;
        }
        return count;    
    }
};
