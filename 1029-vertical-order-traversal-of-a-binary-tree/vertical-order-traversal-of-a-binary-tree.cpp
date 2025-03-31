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
   map<int, map<int, vector<int>>> nodes;

void dfs(TreeNode* root, int row, int col) {
    if (!root) return;
    nodes[col][row].push_back(root->val); // Store values in a vector
    dfs(root->left, row + 1, col - 1);
    dfs(root->right, row + 1, col + 1);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    nodes.clear();
    dfs(root, 0, 0);

    vector<vector<int>> result;
    for (auto& col : nodes) { // Iterate columns in sorted order
        vector<int> colValues;
        for (auto& row : col.second) { // Iterate rows in sorted order
            sort(row.second.begin(), row.second.end()); // Sort values manually
            colValues.insert(colValues.end(), row.second.begin(), row.second.end());
        }
        result.push_back(colValues);
    }
    return result;
}
};