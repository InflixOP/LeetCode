class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int l = getHeight(root->left);
        int r = getHeight(root->right);

        if (abs(l - r) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int l = getHeight(node->left);
        int r = getHeight(node->right);

        return 1 + std::max(l, r);
    }
};
