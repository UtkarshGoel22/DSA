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
    void solve(TreeNode* root, int max, int& ans) {
        if (!root) return;
        if (root->val >= max) {
            ans += 1;
            max = root->val;
        }
        solve(root->left, max, ans);
        solve(root->right, max, ans);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0, max = root->val;
        solve(root, max, ans);
        return ans;
    }
};
