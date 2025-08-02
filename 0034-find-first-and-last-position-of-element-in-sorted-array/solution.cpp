class Solution {
public:

    int firstOccur(vector<int>& nums, int target , int n){
        int st = 0;
        int end = n-1;
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid] == target){
                ans = mid;
                //go left
                end = mid - 1;
            }else if(nums[mid]<target){
                //go right
                st = mid + 1;
            }else{
                //go left
                end = mid - 1;
            }
        }
        return ans;
    }

    int lastOccur(vector<int>& nums, int target , int n){
        int st = 0;
        int end = n-1;
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid] == target){
                ans = mid;
                //go right
                st = mid + 1;
            }else if(nums[mid]<target){
                //go right
                st = mid + 1;
            }else{
                //go left
                end = mid - 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int fo = firstOccur(nums , target , n);
        int lo = lastOccur(nums , target , n);
        
        return {fo,lo};
    }
};
