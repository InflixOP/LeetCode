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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode* > q;
        vector<long long> ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            long long sum=0;
            for(int i=0;i<n;i++){
                TreeNode* p=q.front();
                sum+=p->val;
                q.pop();
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            ans.push_back(sum);
        }
        sort(ans.begin(),ans.end());
        if (k <= ans.size()) {
            return ans[ans.size()-k];
        }
            return -1; 
        
    }
};