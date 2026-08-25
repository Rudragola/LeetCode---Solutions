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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty()) {
            int level = q.size();
            int st = q.front().second;
            int first, last;
            for (int i = 0; i < level; i++) {
                TreeNode* node = q.front().first;
                long curin = q.front().second - st;
                q.pop();
                if (i == 0) {
                    first = curin;
                }
                if (i == level - 1) {
                    last = curin;
                }
                if (node->left) {
                    q.push({node->left, 2 * curin + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * curin + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
