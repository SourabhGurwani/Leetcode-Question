
class Solution {
public:
    void first(TreeNode* root,vector<int> &firstLeaf){
        if (root == nullptr) return;  
        if(root->left==nullptr && root->right==nullptr){
            firstLeaf.push_back(root->val);
            return;

        }
        first(root->left,firstLeaf);
        first(root->right,firstLeaf);
    }
    void second(TreeNode* root,vector<int> &secondLeaf){
        if (root == nullptr) return;  
        if(root->left==nullptr && root->right==nullptr){
            secondLeaf.push_back(root->val);
            return;

        }
        second(root->left,secondLeaf);
       second(root->right,secondLeaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr) return true;
        if(root1==nullptr && root2!=nullptr) return false;
        if(root1==nullptr && root2!=nullptr) return false;
        vector<int> firstLeaf;
        first(root1,firstLeaf);
        vector<int> secondLeaf;
        second(root2,secondLeaf);
        if(secondLeaf.size()!=firstLeaf.size()) return false;
        int check=true;
        for(int i=0;i<secondLeaf.size();i++){
            if(firstLeaf[i]!=secondLeaf[i]){
                check=false;
            }
        }
        return check;
        
    }
};