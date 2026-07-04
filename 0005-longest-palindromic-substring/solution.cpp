class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int start = 0;

        for(int i = 0;i<n;i++){
            //odd
            l = i;
            r = i;
            while(l>= 0 && r<n && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    start = l;
                    maxLen = r-l+1;
                }
                l--;
                r++;
            }

            l= i;
            r = i+1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }

        }
        return s.substr(start , maxLen);
    }
};
