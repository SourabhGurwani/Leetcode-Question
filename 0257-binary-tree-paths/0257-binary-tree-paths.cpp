
class Solution {
public:
void path(TreeNode* root, string s,vector<string> &ans){
    if(root==NULL)return;
    string a=to_string(root->val);
    if(root->left==NULL && root->right==NULL){
        s+=a;
        ans.push_back(s);
        return;
    }
    
    path(root->left,s+a+"->",ans);
    path(root->right,s+a+"->",ans);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        path(root,"",ans);
        return ans;

        
    }
};