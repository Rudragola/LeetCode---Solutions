class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int r = 0;
        int maxi = 0;
        unordered_map<int, int> bas;
        /* while (r < n) {
            bas[fruits[r]]++;
            while (bas.size() > 2) {
                bas[fruits[l]]--;
                if (bas[fruits[l]] == 0) {
                    bas.erase(fruits[l]);
                }
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi; */

        while(r < n){
            bas[fruits[r]]++;
            if(bas.size() > 2){
                bas[fruits[l]]--;
                if(bas[fruits[l]] == 0){
                    bas.erase(fruits[l]);
                }
                l++;
            }
            if(bas.size() <= 2){
                maxi = max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};
