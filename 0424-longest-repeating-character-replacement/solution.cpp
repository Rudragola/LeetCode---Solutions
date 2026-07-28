class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0;
        int r = 0;
        int ans = 0;
        int count[26] = {0};
        int maxFreq = 0;
        while (r < n) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq,count[s[r] - 'A']);

            if ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
