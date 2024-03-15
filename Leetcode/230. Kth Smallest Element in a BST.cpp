/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void kthSmallestUtil(TreeNode* root, int& count, int& ans, int k) {
        if (!root) return;
        kthSmallestUtil(root->left, count, ans, k);
        if (++count == k) {
            ans = root->val;
            return;
        }
        kthSmallestUtil(root->right, count, ans, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, ans;
        kthSmallestUtil(root, count, ans, k);
        return ans;
    }
};
