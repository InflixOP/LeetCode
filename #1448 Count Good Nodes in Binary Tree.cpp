/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        answer(root, count, -100000);
        return count;
    }
    void answer(TreeNode* root, int& count, int max) {
        if (!root)
            return;
    if(root->val>=max){
    count++;
    max=root->val;
    }
    answer(root->left,count,max);
    answer(root->right,count,max);
    }
};