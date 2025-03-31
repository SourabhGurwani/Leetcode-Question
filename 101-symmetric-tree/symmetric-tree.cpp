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
 bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;   // Both nodes are NULL → Symmetric
        if (!t1 || !t2) return false;  // One node is NULL but the other isn't → Not symmetric
        return (t1->val == t2->val)    // Check values
            && isMirror(t1->left, t2->right)  // Left of `t1` vs. Right of `t2`
            && isMirror(t1->right, t2->left); // Right of `t1` vs. Left of `t2`
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
        
    }
};