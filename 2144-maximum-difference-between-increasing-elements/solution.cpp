class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       /*  //better 
        int n = nums.size();
        int mini = nums[0];
        int maxi = -1;
        for(int i =1;i<n;i++){
            if(nums[i] <= mini){ //here if no "=" then it will change m,aximum to 0n not return -1
                mini = nums[i];
            }else{
                int sub = nums[i] - mini;
                maxi = max(sub,maxi);
            }
        }
        return maxi; */

        //optimal 
        int n = nums.size();
        int diff = nums[1] - nums[0];
        int curSum = diff;
        int maxSum = -1;

        if(curSum > 0) maxSum = curSum ;

        for(int i = 1;i<n-1;i++){
            diff = nums[i+1] - nums[i];

            if(curSum > 0){
                curSum += diff;
            }else{
                curSum = diff;
            }

            if (curSum > 0 && curSum > maxSum){
                maxSum = curSum; 
            }
        }
        return maxSum ;         
    }
};
