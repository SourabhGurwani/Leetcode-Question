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
   bool isBalancedHelper(TreeNode* root, int &height) {
    if (!root) {
        // height = 0;
        return true; 
    }

    int leftHeight = 0, rightHeight = 0;

    
    bool leftBalanced = isBalancedHelper(root->left, leftHeight);
    bool rightBalanced = isBalancedHelper(root->right, rightHeight);

   
    if (!leftBalanced || !rightBalanced || abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    
    height = max(leftHeight, rightHeight) + 1;
    return true;
}


bool isBalanced(TreeNode* root) {
    int height = 0;
    return isBalancedHelper(root, height);

    }
};