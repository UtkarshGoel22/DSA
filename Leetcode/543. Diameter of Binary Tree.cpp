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
public:
    
    static int height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int lheight = height(root->left);
        int rheight = height(root->right);
        int ldiameter = diameterOfBinaryTree(root->left);
        int rdiameter = diameterOfBinaryTree(root->right);
        return max(lheight + rheight , max(ldiameter, rdiameter));
    }
};

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
    vector<int> findHeightAndDiameter(TreeNode* root) {
        if (!root) return {0, 0};
        vector<int> left = findHeightAndDiameter(root->left);
        vector<int> right = findHeightAndDiameter(root->right);
        int currentHeight = max(left[0], right[0]) + 1;
        int currentDiameter = max(left[0] + right[0], max(left[1], right[1]));
        return {currentHeight, currentDiameter};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return findHeightAndDiameter(root)[1];
    }
};

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
    pair<int, int> findHeightAndDiameter(TreeNode* root) {
        if (!root) return {0, 0};
        pair<int, int> left = findHeightAndDiameter(root->left);
        pair<int, int> right = findHeightAndDiameter(root->right);
        int currentHeight = max(left.first, right.first) + 1;
        int currentDiameter = max(left.first + right.first, max(left.second, right.second));
        return {currentHeight, currentDiameter};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return findHeightAndDiameter(root).second;
    }
};
