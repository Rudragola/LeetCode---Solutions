class Solution {
public:
    void sortColors(vector<int>& nums) {
        /* int count=0, count1=0 ,count2 = 0;
        int n = nums.size();

        for(int i =0;i<n;i++){
            if(nums[i] == 0){
                count++;
            }else if(nums[i] == 1){
                count1++;
            }else{
                count2++;
            }
        }
        int j =0;
        for(int i = 0;i<n;i++){
            if(count>i){
                nums[i] = 0;
                j++;
            }
            else if(i<j+count1){
                nums[i] = 1;
            }
            else{
                nums[i] = 2;
            }

        } */

        int n =nums.size();
        int low = 0,mid = 0,high = n-1;

        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[mid] , nums[low]);
                low++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid] , nums[high]);
                high--;
            }
        }
        
    }
};
