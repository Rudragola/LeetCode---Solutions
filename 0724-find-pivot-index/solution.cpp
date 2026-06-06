class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        int ts = 0;
        int ls =0,rs = 0;
        for(int i =0;i<n;i++){
            ts += nums[i];
        }

        for(int i =0;i<n;i++){
            rs = ts - nums[i] - ls;

            if(ls == rs){
                return i;
            }

            ls += nums[i];
        }
        return -1;
    }
};
