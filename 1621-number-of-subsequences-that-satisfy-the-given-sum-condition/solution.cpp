class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int left = 0;
        int right = n- 1;
        int MOD = 1000000007;
        int ans = 0;
        vector<int> pow2(n,1);
        for(int i = 1;i<n;i++){
            pow2[i] = pow2[i-1]*2LL % MOD;
        }

        while(left <= right){
            if((nums[left] + nums[right]) > target){
                right--;
            }else{
                ans = (ans+ pow2[right - left]) % MOD;
                left++;
            }
        }
        return ans;
    }
};
