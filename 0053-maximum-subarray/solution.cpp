class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for(int i =1;i<nums.size();i++){
            
            int option1 = nums[i];
            int option2 = currentSum + nums[i];
            currentSum = max(option1 , option2);

            if(currentSum>maxSum){
                maxSum = currentSum;
            }
        }
        return maxSum;

        /* int curSum = 0;
        int maxSum = INT_MIN;

        for(int i =0;i<nums.size();i++){
            curSum+=nums[i];
            maxSum = max(curSum,maxSum);
            if(curSum<0){
                curSum = 0;
            }
        }
        return maxSum; */
    }
};
