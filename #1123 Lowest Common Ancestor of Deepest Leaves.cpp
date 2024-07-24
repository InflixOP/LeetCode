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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
    pair<TreeNode*,int> dfs(TreeNode* root){
        if(!root)
        return{ NULL,0};
        auto [lc,ld]=dfs(root->left);
        auto [lr,rd]=dfs(root->right);
        if(ld>rd)
        return {lc,1+ld};
        if(ld<rd)
        return {lr,1+rd};
        return {root,1+ld};
    }
};