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
    int averageOfSubtree(TreeNode* root) {
     int count=0;
        dfs(count,root);
        return count;
    }
    int dfs(int& count,TreeNode* root){
        if(!root)
            return 0;
        int l=dfs(count,root->left);
        int r=dfs(count,root->right);
        int c=count1(root);
        int sum=root->val+l+r;
        int avg = std::floor(static_cast<double>(sum)/c);
        if(root->val==avg)
            count++;
        return sum;
    }
    int count1(TreeNode* root){
        if(!root)
            return 0;
        return 1+count1(root->left)+count1(root->right);
    }
};