class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    
private:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root) {
            inorder(root->left, result);
            result.push_back(root->val);
            inorder(root->right, result);
        }
    }
};
