class Solution {
public:
    void recur(string& digits, string map[], vector<string>& ans, string& cur,int inx) {
        if (inx >= digits.length()) {
            ans.push_back(cur);
            return;
        }

        int dig = digits[inx] - '0';
        string mapp = map[dig];

        for (int i = 0; i < mapp.length(); i++) {
            cur.push_back(mapp[i]);
            recur(digits, map, ans, cur, inx + 1);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur;
        string map[10] = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
        recur(digits, map, ans, cur, 0);
        return ans;
    }
};
