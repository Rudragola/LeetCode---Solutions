class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Brute is to apply two for loop 

        //better is using hash array

        //OPTIMAL

        //sum
        int n = nums.size();
        int sum = (n*(n+1))/2;
        for(int i = 0;i<n;i++){
            sum -= nums[i];
        }
        return sum;

        //xor
        /* int n = nums.size();
        int XOR1 = 0;
        int XOR2 =0 ;
        for(int i = 0;i<n;i++){
            XOR1 = XOR1 ^ (i+1);
            XOR2 = XOR2^nums[i];
        }
        XOR2 = XOR1 ^ XOR2;

        return XOR2; */
    }
};
