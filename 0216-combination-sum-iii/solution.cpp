class Solution {
public:
    void recur(int i, vector<int>& cur, vector<vector<int>>& ans, int k, int n) {
        // 1. Success Base Case
        if (n == 0 && k == 0) {
            ans.push_back(cur);
            return;
        }
        
        // 2. Boundary Base Case
        if (i == 10) {
            return;
        }
        
        // 3. Early Pruning (Optimization)
        // If we exceed the required numbers or the required sum, stop immediately.
        if (k < 0 || n < 0) {
            return;
        }

        // Branch 1: PICK
        cur.push_back(i);
        recur(i + 1, cur, ans, k - 1, n - i);
        cur.pop_back();

        // Branch 2: DON'T PICK
        recur(i + 1, cur, ans, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        // Declared LOCALLY so they reset on every LeetCode test case!
        vector<vector<int>> ans;
        vector<int> cur;
        
        recur(1, cur, ans, k, n);
        
        return ans;
    }
};
