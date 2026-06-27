class Solution {
public:
    bool isDivisor(vector<int>& nums, int mid, int thr) {
        int sum = 0;
        for (int i : nums) {
            sum += (i + mid - 1) / mid;
            if(sum > thr) return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isDivisor(nums, mid, threshold)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
