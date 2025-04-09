
class Solution {
public:
    
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> out;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> in;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                in.push_back(node->val);
                q.pop();
                 if(node->left) q.push(node->left);
                 if(node->right) q.push(node->right);
            }
            out.push_back(in);
           
        }
        vector<int> sumvec;
        for(const auto& level:out){
            int sum=0;
            for(int i:level){
                sum=sum+i;
            }
            sumvec.push_back(sum);
        }
        int max=sumvec[0];
        int idx=0;

        for(int i=1;i<sumvec.size();i++){
            if(max<sumvec[i]){
                idx=i;
                max=sumvec[i];
            }
        }
        return idx+1;

        
    }
};