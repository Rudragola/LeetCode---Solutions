class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0;
        int r = 0;
        while (r < n) {
            int fart = 0;
            for (int i = l; i <= r; i++) {
                fart = max(fart, i + nums[i]);
            }
            if(r >= n-1){
                return jumps;
            }
            l = r + 1;
            r = fart;
            jumps++;
            
        }
        return jumps;
    }
};
