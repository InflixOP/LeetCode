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
    int minDepth(TreeNode* root) {
     return Height(root);
    }
    int Height(TreeNode *p) {
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }
 
    l = Height(p->left);
    r = Height(p->right);
 
    if (p->left==nullptr){
        return r + 1;
    } 
        if(p->right==nullptr){
        return l + 1;
    }   
        return min(l,r)+1;
    }
};