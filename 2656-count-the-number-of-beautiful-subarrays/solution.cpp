class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int xr = 0;
        long long cnt = 0;
        mpp[xr] = 1;

        for(int i = 0;i<n;i++){
            xr = xr^nums[i];
            cnt+=mpp[xr];
            mpp[xr]++;
        }
        return cnt;

    }
};
