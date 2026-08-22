/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int flag = true;
        // flag == 0 means to go right to left
        // flag == 1 means to go left to right

        while (!q.empty()) {
            int level = q.size();
            vector<int> curr(level);

            for (int i = 0; i < level; i++) {
                TreeNode* cur = q.front();
                q.pop();

                int inx = flag ? i : (level - 1 - i);
                curr[inx] = cur->val;
                if (cur->left != NULL) {
                    q.push(cur->left);
                }
                if (cur->right != NULL) {
                    q.push(cur->right);
                }
            }
            ans.push_back(curr);
            flag = !flag;
        }
        return ans;
    }
};
