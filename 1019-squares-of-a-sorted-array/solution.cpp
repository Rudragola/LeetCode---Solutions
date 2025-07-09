class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,0);

        int i = 0;
        int j = n-1;
        int index = n-1;
        while(i<=j){
            if(abs(nums[i]) > abs(nums[j])){
                answer[index] = nums[i] * nums[i];
                i++;
            }
            else{
                answer[index] = nums[j] * nums[j];
                j--;
            }
            index--;
        }
        return answer;
    }
};
