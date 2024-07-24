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
    vector<int> largestValues(TreeNode* root) {
       vector<int> ans;
       if(!root)
       return {};
        queue<  TreeNode*> q;
    TreeNode *t=root;
    q.emplace(t);
    int sum=0;
    while(!q.empty())
    {   
        sum=-2147483648;
        int n=q.size();
        for(int i=0;i<n;i++){
            t=q.front();
            sum=max(sum,t->val);
            if(t->left)
            q.emplace(t->left);
             if(t->right)
            q.emplace(t->right);
            q.pop();
        }
        ans.push_back(sum);
    }
    return ans;
    }
};