/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root , string cur, vector<string>& ans){
        if(!root) return;

        cur += to_string(root->val);

        if(!root->left && !root->right){
            ans.push_back(cur);
            return;
        }

        if(root->left) dfs(root->left , cur+"->", ans);
        if(root->right) dfs(root->right , cur+"->", ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string cur;
        dfs(root , cur , ans);
        return ans;
    }
};
