
class Solution {
public:
    
    TreeNode* invertTree(TreeNode* root) {
        // change(root->right,root->left);
        if(!root) return NULL;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        invertTree(root->left);
        invertTree(root->right);
                return root;
        
    }
};