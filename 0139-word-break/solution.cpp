class Solution {
public:
    // Added memo array passed by reference
    bool recur(int si, const string& s, const unordered_set<string>& wordSet, vector<int>& memo) {
        if (si == s.length()) {
            return true;
        }

        // If we've already computed this index, return the saved result!
        if (memo[si] != -1) {
            return memo[si] == 1;
        }

        for (int ei = si + 1; ei <= s.length(); ei++) {
            string current = s.substr(si, ei - si);
            if (wordSet.count(current)) {
                if (recur(ei, s, wordSet, memo)) {
                    memo[si] = 1; // Save success before returning
                    return true;
                }
            }
        }
        
        // Save failure before returning so we never compute this index again
        memo[si] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // Initialize memo array of size s.length() with -1 (unvisited)
        vector<int> memo(s.length(), -1);
        
        return recur(0, s, wordSet, memo);
    }
};
