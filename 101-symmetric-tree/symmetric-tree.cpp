class Solution {
public:
    void rightf(TreeNode* root, vector<int>& right) {
        if (root == nullptr) {
            right.push_back(-101); // Unique marker for NULL
            return;
        }
        right.push_back(root->val);
        rightf(root->right, right);
        rightf(root->left, right);
    }

    void leftf(TreeNode* root, vector<int>& left) {
        if (root == nullptr) {
            left.push_back(-101); // Unique marker for NULL
            return;
        }
        left.push_back(root->val);
        leftf(root->left, left);
        leftf(root->right, left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        vector<int> right, left;
        rightf(root->right, right);
        leftf(root->left, left);

        if (right.size() != left.size()) return false;

        for (int i = 0; i < right.size(); i++) {
            if (right[i] != left[i]) return false;
        }
        return true;
    }
};
