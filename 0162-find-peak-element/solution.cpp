class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1]) {
                // peak is at mid or on left side
                high = mid;
            } else {
                // nums[mid] < nums[mid+1], peak is on right side
                low = mid + 1;
            }
        }
        return low; // low == high == index of a peak
    }
};
