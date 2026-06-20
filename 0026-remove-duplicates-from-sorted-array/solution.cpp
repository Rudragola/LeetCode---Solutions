class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count  = 0;
        int n = nums.size();

        int i = 0;
        int j = 1;
        while(i<n && j<n){
            if(nums[i] == nums[j]){
                j++;
            }else{
                i++;
                swap(nums[i] , nums[j]);
                j++;
            }
        }
        return i+1;
    }
};
