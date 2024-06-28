class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, nullptr);
    }
    
    TreeNode* dfs(vector<int> &pre, vector<int> &in, TreeNode *parent) {
        if (pre.empty() || parent && in[0] == parent->val)
            return nullptr;
        
        TreeNode *curr = new TreeNode(pre[0]);
        pre.erase(pre.begin());
        curr->left = dfs(pre, in, curr);
        in.erase(in.begin());
        curr->right = dfs(pre, in, parent);
        return curr;
    }
};