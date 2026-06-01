class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int ele = nums[0];
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] == ele){
                freq++;
            }else if(freq == 0){
                ele = nums[i];
                freq++;
            }
            else{
                freq--;
            }
        }
        
        return ele;
        
    }
};
