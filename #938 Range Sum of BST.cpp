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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* p=q.front();
            q.pop();
                if(p->val>=low&&p->val<=high)
                    sum+=p->val;
            
            if(p->left&&p->val>low)
                q.push(p->left);
            if(p->right&&p->val<high)
                q.push(p->right);
        }}
        return sum;
    }
};