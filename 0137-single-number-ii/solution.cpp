class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int two = 0;

        for (int i = 0; i < n; i++) {
            ones = (ones ^ nums[i]) & ~two;
            two = (two ^ nums[i]) & ~ones;
        }
        return ones;
    }
};
