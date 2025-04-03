class Codec {
public:
    // Encodes a tree to a single string (Serialization).
    string serialize(TreeNode* root) {
        if (!root) return "";

        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ss << node->val << ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "N,";
            }
        }

        return ss.str();
    }

    // Decodes your encoded data to tree (Deserialization).
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Process left child
            if (getline(ss, val, ',') && val != "N") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            // Process right child
            if (getline(ss, val, ',') && val != "N") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }

        return root;
    }
};
