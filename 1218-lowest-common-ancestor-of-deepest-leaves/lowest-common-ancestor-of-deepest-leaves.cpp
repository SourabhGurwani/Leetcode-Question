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
      pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {nullptr, -1}; // Return -1 so root is at depth 0

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.second == right.second) {
            return {root, left.second + 1}; // LCA of deepest nodes
        } else if (left.second > right.second) {
            return {left.first, left.second + 1};
        } else {
            return {right.first, right.second + 1};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};