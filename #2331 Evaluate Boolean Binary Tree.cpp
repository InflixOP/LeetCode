class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == 0)
                return false;
            return true;
        }
        
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        
        if (root->val == 2)
            return left || right;
        return left && right;
    }
};
