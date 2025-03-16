class Solution {
public:
    int maxi=0;
    int level(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dai= level(root->left)+level(root->right);
        maxi=max(dai,maxi);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;

   
        
        
    }
};