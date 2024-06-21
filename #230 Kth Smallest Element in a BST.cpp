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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode* > q;
        vector<int> ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* p=q.front();
                ans.push_back(p->val);
                q.pop();
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};