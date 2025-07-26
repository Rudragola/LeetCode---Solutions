class Solution {
public:
    int firstOccur(vector<int>& nums, int target){
        int str = 0;
        int end = nums.size() -1;
        int first = -1;

        while(str<=end){
            int mid = str + (end - str)/2;

            if(nums[mid] == target){
                first = mid;
                //go left
                end = mid - 1;
            }else if(target<nums[mid]){
                end= mid - 1;
            }else{
                str = mid + 1;
            }
        }
        return first;
    }

    int lastOccur(vector<int>& nums, int target){
        int str = 0;
        int end = nums.size() -1;
        int last = -1;

        while(str<=end){
            int mid = str + (end - str)/2;

            if(nums[mid] == target){
                last = mid;
                //go right
                str = mid + 1;
            }else if(target<nums[mid]){
                end= mid - 1;
            }else{
                str = mid + 1;
            }
        }
        return last;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int fo = firstOccur(nums , target);
        int lo = lastOccur(nums , target);
        return {fo , lo};
    }
};
