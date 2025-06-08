class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1;i<nums.size();i++){
            int option1 = nums[i];
            int option2 = currentSum+nums[i];
            currentSum = max(option1,option2);

            if(currentSum>maxSum){
                maxSum = currentSum;
            }
        }
        return maxSum;
    }
};
