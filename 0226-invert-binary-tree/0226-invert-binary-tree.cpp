
class Solution {
public:
void ulta(TreeNode* root){
    if(root==NULL)return;
    TreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;
    ulta(root->left);
    ulta(root->right);
}
    TreeNode* invertTree(TreeNode* root) {
        ulta(root);
        return root;
        
    }
};