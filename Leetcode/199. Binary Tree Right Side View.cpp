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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) 
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode *prev, *temp = q.front();
        while(!q.empty()) {
            prev = temp;
            temp = q.front();
            q.pop();
            if(temp == NULL) {
                if(prev) 
                    res.push_back(prev->val);
                if(!q.empty())
                    q.push(NULL);
            }
            else {
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return res;
    }
};
