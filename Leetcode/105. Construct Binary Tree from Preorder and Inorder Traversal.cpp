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
    TreeNode* construct(vector<int>& preorder, unordered_map<int, int>& mp, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int index = mp[root->val];
        root->left = construct(preorder, mp, ps+1, ps+index, is, index-1);
        root->right = construct(preorder, mp, ps+index-is+1, pe, index+1, ie);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> mp; // value, index in inorder traversal array.
        for (int i = 0; i < n; i++) mp[inorder[i]] = i; // To optimize getIndex TC to O(1).
        return construct(preorder, mp, 0, n-1, 0, n-1);
    }
};
