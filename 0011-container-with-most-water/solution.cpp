class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi =INT_MIN;
        int cur = 0;
        int i = 0;
        int j = n-1;
        while(i<j){
            int x = j-i;
            if(height[i] > height[j]){
                cur = height[j]*x;
                j--;
            }else{
                cur = height[i]*x;
                i++;
            }
            maxi = max(cur , maxi);
        }
        return maxi;
    }
};
