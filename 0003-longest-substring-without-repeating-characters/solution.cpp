class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mpp;
        int l = 0;
        int r = 0;
        int ans = 0;

        while(r<n){
            if(mpp.contains(s[r]) && mpp[s[r]] >= l){
                l = mpp[s[r]] + 1;
            }

            mpp[s[r]] = r;

            ans = max(ans , r - l + 1);
            r++;
        }
        return ans;
    }
};
