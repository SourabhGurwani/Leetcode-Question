
class Solution {
public:
    bool find(TreeNode* root,TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return find(root->left, target)|| find(root->right,target);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        else if(find(root->left,p) && find(root->right,q)) return root;
        else if(find(root->left,q) && find(root->right,p)) return root;
        else if(find(root->left,q) && find(root->left,p)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);

        
    }
};