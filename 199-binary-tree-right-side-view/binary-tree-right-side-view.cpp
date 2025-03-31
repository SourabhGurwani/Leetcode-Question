class Solution {
public:
    void right(TreeNode* root,vector<int> &result,int count){
        if(root==nullptr) return;
        if (count == result.size()) {
            result.push_back(root->val);
        }

        right(root->right,result,count+1);
       
        right(root->left,result,count+1);
      
       
        

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==nullptr) return result;
        right(root,result,0);
        return result;
        

        
    }
};