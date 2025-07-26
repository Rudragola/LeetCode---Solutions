class Solution {
public:
    int mySqrt(int x) {
        long long st = 1;
        long long end = x;
        long long ans = x;

        while (st <= end) {
            long long mid = st + (end - st) / 2;

            if (mid * mid <= x) {
                ans = mid;
                // go right
                st = mid + 1;
            } else {
                // go left
                end = mid - 1;
            }
        }
        return (int)ans;
    }
};
