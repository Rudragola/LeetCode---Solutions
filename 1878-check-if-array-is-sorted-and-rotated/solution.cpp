class Solution {
public:
    bool check(vector<int>& nums) {
        int breakC = 0;
        int n = nums.size();
        for(int i =0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                breakC++;
            }
        }

        if(breakC == 0){
            return true;
        }else if(breakC>1){
            return false;
        }else{
            if(nums[n-1]<=nums[0]){
                return true;
            }
        }
        return false;
    }
};
