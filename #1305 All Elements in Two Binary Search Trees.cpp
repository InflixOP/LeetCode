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
        vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        getall(root1,ans);
        getall(root2,ans);
        sort(ans.begin(),ans.end()); 
        return ans;
        }
        void getall(TreeNode* root,vector<int>& ans){
            if(!root)
            return;
            ans.push_back(root->val);
            getall(root->left,ans);
            getall(root->right,ans);

        }
        
    };