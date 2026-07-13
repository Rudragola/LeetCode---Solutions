class Solution {
public:
    vector<vector<int>> ans;
    void recur(int i, vector<int>& nums, int tar, vector<int>& cur, int curr) {
        if (curr == tar) {
            ans.push_back(cur);
            return;
        }
        if (i == nums.size())
            return;
        if (nums[i] + curr <= tar) {
            cur.push_back(nums[i]);
            recur(i + 1, nums, tar, cur, curr + nums[i]);
            cur.pop_back();
        }
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        recur(i + 1, nums, tar, cur, curr);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) {
        sort(nums.begin() , nums.end());
        vector<int> cur;
        recur(0, nums, tar, cur, 0);
        return ans;
    }
};
