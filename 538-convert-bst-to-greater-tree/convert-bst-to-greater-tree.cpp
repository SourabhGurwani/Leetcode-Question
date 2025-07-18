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
    int sum=0;
    void convert(TreeNode* root){
        // if(!root->left && !root->right){
        //     sum=root->val;
        //     return ;
        // }
        if (root == nullptr) return;
        convert(root->right);
        sum=sum+root->val;
        root->val=sum;
        convert(root->left);
        return;
        // root->val=sum;
        
    }
    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
        
    }
};