class Solution {
public:

    int firstOccur(vector<int>& nums , int n , int target ){
        int low = 0 ;
        int high = n-1;
        int ans = -1;

        while(low <= high){
            int mid = (low+high) /2;
            if(nums[mid] == target){
                ans = mid;
                high = mid-1;
            }else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }

    int lastOccur(vector<int>& nums , int n , int target ){
        int low = 0 ;
        int high = n-1;
        int ans = -1;

        while(low <= high){
            int mid = (low+high) /2;
            if(nums[mid] == target){
                ans = mid;
                low = mid+1;
            }else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccur(nums , nums.size() , target) ,lastOccur(nums , nums.size() , target) };
    }
};
