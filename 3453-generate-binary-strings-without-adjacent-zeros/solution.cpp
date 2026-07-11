class Solution {
public:
    void backtrack(int pos, int prev, string curr, vector<string>& result, int n) {
        if (pos == n) {
            result.push_back(curr);
            return;
        }

        // backtrack for first 0;
        backtrack(pos + 1, 1, curr + "1", result, n);

        if (prev == 1) {
            backtrack(pos + 1, 0, curr + "0", result, n);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> result;
        backtrack(0, 1, "", result, n);
        return result;
    }
};
