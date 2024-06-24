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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* p;
        while(!q.empty()){
            double sum=0;
            double n=q.size();
            for(int i=0;i<n;i++){
                p=q.front();
                q.pop();
                sum+=p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ans.push_back(sum/n);
        }
        return ans;
    }
};