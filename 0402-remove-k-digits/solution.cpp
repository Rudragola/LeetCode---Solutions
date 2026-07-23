class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int n = num.length();
        for (int i = 0; i < n; i++) {
            while (!ans.empty() && k && num[i] < ans.back()) {
                ans.pop_back();
                k--;
            }

            if (ans.empty() && num[i] == '0') {
                continue;
            } else {
                ans.push_back(num[i]);
            }
        }

        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        return ans.empty()?"0":ans;
    }
};
