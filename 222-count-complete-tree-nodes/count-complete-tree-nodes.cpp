
class Solution {
public:
    int count=0;
    void complete(TreeNode* root){
        if(root==nullptr) return ;
        if(root->left){
            complete(root->left);
            count++;
        }
         if(root->right){
            complete(root->right);
            count++;
        }

    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        count++;
        complete( root);
        return count;
        
    }
};