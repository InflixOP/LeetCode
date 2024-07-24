class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size() - 1;
        unordered_map<int, int> map;
        
        for (int i = 0; i < inorder.size(); ++i) {
            map[inorder[i]] = i;
        }

        return build(inorder, postorder, map, idx, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& map, int& idx, int start, int end) {
        if (start > end) return nullptr;

        TreeNode* node = new TreeNode(postorder[idx--]);

        node->right = build(inorder, postorder, map, idx, map[node->val] + 1, end);
        node->left = build(inorder, postorder, map, idx, start, map[node->val] - 1);

        return node;
    }
};