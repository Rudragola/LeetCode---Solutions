class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int inx = -1;

        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                inx = i;
                break;
            }
        }
        if(inx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i = n-1;i>inx;i--){
            if(nums[i]>nums[inx]){
                swap(nums[i],nums[inx]);
                break;
            }
        }

        reverse(nums.begin()+(inx+1) , nums.end());
        
    }
};
