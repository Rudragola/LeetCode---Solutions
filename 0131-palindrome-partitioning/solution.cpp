class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void recur(int start, string& s, vector<vector<string>>& ans,
               vector<string>& cur) {
        if (start == s.length()) {
            ans.push_back(cur);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                cur.push_back(s.substr(start, end - start + 1));
                recur(end + 1, s, ans, cur);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur = {};
        recur(0, s, ans, cur);
        return ans;
    }
};
