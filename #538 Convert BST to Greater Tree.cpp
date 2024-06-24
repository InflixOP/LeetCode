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
    TreeNode* convertBST(TreeNode* root) {
        vector<int> use;
        if(root==nullptr){
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* p;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                p=q.front();
                q.pop();
                use.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
    sort(use.begin(),use.end());
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                p=q.front();
                q.pop();
                auto it = std::upper_bound(use.begin(), use.end(), p->val);
    int sum = 0;
    for (auto iter = it; iter != use.end(); iter++) {
        sum += *iter;
    }
                p->val+=sum;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return root;
    }
};