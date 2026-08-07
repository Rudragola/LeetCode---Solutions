class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int inx = -1;
        int n = nums.size();
        for (int i = n-1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                inx = i;
                break;
            }
        }

        if (inx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n-1; i >= 0; i--) {
            if (nums[i] > nums[inx - 1]) {
                swap(nums[i], nums[inx - 1]);
                break;
            }
        }

        reverse(nums.begin() + (inx), nums.end());
        return;
    }
};
