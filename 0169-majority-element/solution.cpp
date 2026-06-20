class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq = 0;
        int ans = nums[0];
        for(int i = 0;i<n;i++){
            if(nums[i] == ans){
                freq++;
            }else if(freq == 0){
                ans = nums[i];
                freq++;
            }else {
                freq--;
            }
        }
        return ans;
    }
};
