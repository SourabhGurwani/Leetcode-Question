
class Solution {
public:
int level(TreeNode* root){
    if(root==NULL)return 0;
    TreeNode* Left=root->left;
    TreeNode* right=root->right;
    return 1 + max(level(Left),level(right));
}
void nthLevel(TreeNode* root,int curr, int lvl,vector<int> &level){
    if(root==NULL)return;
    if(curr==lvl){
        level.push_back(root->val);
        return;
    }
    nthLevel(root->left,curr+1,lvl,level);
    nthLevel(root->right,curr+1,lvl,level);
}
void levelorder(TreeNode* root,vector<vector<int>> &res){
    if(root==NULL)return;
    int n=level(root); 
    for(int i=1;i<=n;i++){
        vector<int>level;
        nthLevel(root,1,i,level);
        res.push_back(level);
    }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        levelorder(root,res);
        return res;






        
        
    }
};