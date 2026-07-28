class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int  r = 0;
        int ans = 0;
        int p[3] = {-1,-1,-1};
        while(r<n){
            p[s[r] - 'a'] = r;

            if(p[0] != -1 && p[1] != -1 && p[2] != -1){
                int l = min({p[0], p[1], p[2]});
                ans += l+1;
            }
            r++;
        }
        return ans;
    }
};
