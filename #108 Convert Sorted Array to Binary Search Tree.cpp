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
   TreeNode* func(vector<int>& nums, int i, int j){
        if (i > j) return NULL;
        
        int m = (i+j)/2;
        TreeNode* root = new TreeNode(nums[m]);

        root->left = func(nums,i,m-1);
        root->right = func(nums,m+1,j);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = func(nums,0,n-1);
        return root;
    }
};