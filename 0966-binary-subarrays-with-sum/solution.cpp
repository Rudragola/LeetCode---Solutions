class Solution {
public:
    int lesserEqual(vector<int>& nums, int goal) {
        if(goal < 0)return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        int sum = 0;
        while (r < n) {
            sum += nums[r];
            while (sum > goal) {
                sum = sum - nums[l];
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return lesserEqual(nums, goal) - lesserEqual(nums, goal - 1);
    }
};
