class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lMax = 0;
        int rMax = 0;
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l < r){
            lMax = max(lMax , height[l]);
            rMax = max(rMax , height[r]);

            if(lMax < rMax){
                ans += min(lMax,rMax) - height[l];
                l++;
            }else{
                ans += min(lMax,rMax) - height[r];
                r--;
            }
        }
        return ans;
    }
};
