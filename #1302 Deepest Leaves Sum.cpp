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
    int deepestLeavesSum(TreeNode* root) {
        vector<int> ans;
        int high=height(root);
        int sum=0;
        dfs(sum,root,high,0);
        return sum;
    }
    int height(TreeNode* p){
        int l=0;
    int r=0;
    if (p == nullptr){
        return 0;
    }
    l=height(p->left);
    r=height(p->right);
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
    }
    void dfs(int& sum,TreeNode* root,int height,int h){
        if(!root)
            return;
        h++;
        if(!root->left&&!root->right&&h==height){
            sum+=root->val;
            return;
        }
        dfs(sum,root->left,height,h);
        dfs(sum,root->right,height,h);
    }
};