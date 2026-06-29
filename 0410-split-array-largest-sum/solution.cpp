class Solution {
public:

    bool isPossible(vector<int>& nums,int mid , int k){
        int cnt = 1;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            if(sum > mid){
                cnt++;
                sum = nums[i];
            }
            if(cnt > k) return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end() , 0);
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(nums , mid , k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
