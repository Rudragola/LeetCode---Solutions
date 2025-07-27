class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() -1;

        while(st<= end){
            int mid = st + (end - st)/2;

            if(nums[mid] == target){
                return mid;
            }

            //left sorted
            if(nums[st] <= nums[mid]){
                //left
                if(target<= nums[mid] && nums[st]<=target){
                    end = mid - 1;
                }
                //right
                else{
                    st = mid + 1;
                }
            }
            //right sorted
            else{
                //right
                if(target>=nums[mid] && target <= nums[end]){
                    st = mid + 1;
                }
                //left
                else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
