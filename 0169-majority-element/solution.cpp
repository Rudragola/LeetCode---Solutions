class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq = 0;
        int ele = nums[0];

        for(int i = 0;i<n;i++){
            if(ele == nums[i]){
                freq++;
            }else if(freq == 0){
                ele = nums[i];
                freq++;
            }else{
                freq--;
            }
        }
        return ele;
    }
};
