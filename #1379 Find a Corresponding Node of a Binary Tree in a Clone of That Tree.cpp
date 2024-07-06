/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned, target);
    }
    TreeNode* dfs(TreeNode* root, TreeNode* target) {
        if (!root)
            return nullptr;   
        if (root->val == target->val)
            return root;
        TreeNode* leftResult = dfs(root->left, target);
        if (leftResult)
            return leftResult;
        
        TreeNode* rightResult = dfs(root->right, target);
        if (rightResult)
            return rightResult;
        
        return nullptr;
    }
};
