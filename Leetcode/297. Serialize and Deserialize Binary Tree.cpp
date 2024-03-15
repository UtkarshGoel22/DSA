/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    TreeNode* deserialize_helper(queue<string>& q) {
        string s = q.front();
        q.pop();
        if (s == "null") return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = deserialize_helper(q);
        root->right = deserialize_helper(q);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null,";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        int n = data.length();
        for (int i = 0; i < n; i++) {
            if (data[i] == ',') {
                q.push(s);
                s = "";
                continue;
            }
            s += data[i];
        }
        return deserialize_helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
