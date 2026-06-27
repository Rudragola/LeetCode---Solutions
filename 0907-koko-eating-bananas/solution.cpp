class Solution {
public:
    int maxi(vector<int>& piles, int n) {
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (piles[i] >= max) {
                max = piles[i];
            }
        }
        return max;
    }
    bool canEatAll(vector<int>& piles, int s, int h) {
        long long totalHour = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalHour += ceil((double)piles[i] / (double)s);
        }
        return (totalHour <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = maxi(piles, n);
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canEatAll(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
