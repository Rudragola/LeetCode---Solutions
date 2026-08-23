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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> todo;
        // node , vertical , level
        map<int, map<int, multiset<int>>> nodes;
        // vertical , level , vertical elements
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* cur = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(cur->val);

            if (cur->left != NULL) {
                todo.push({cur->left, {x - 1, y + 1}});
            }
            if (cur->right != NULL) {
                todo.push({cur->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto it : nodes) {
            vector<int> col;
            for (auto it2 : it.second) {
                col.insert(col.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
