class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       /* int i = 0;
       int j = i+1;
       int n = nums.size();
       int count = 0;

       while(i<n && j<n){
        if(nums[i] == nums[j]){
            j++;
        }else{
            i++;
            nums[i] = nums[j];
            count++;
        }
       }
       return count + 1 ; */
       int i = 0;
       for(int j = 1;j<nums.size();j++){
        if(nums[i] !=nums[j]){
            i++;
            nums[i] = nums[j];
        }
       }
       return i+1;
    }
};

