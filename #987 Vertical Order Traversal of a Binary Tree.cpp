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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
int mini=INT_MAX,maxi=INT_MIN;
        map<pair<int,int>,vector<int>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode*temp=q.front().first;
            int v=q.front().second.first;
            int l=q.front().second.second;
            q.pop();
            mini=min(mini,v);
            maxi=max(maxi,v);
            mp[{v,l}].push_back(temp->val);
            if(temp->left!=NULL)q.push({temp->left,{v-1,l+1}});
            if(temp->right!=NULL)q.push({temp->right,{v+1,l+1}});
        }
    vector<vector<int>>ans(maxi-mini+1);
    for(auto it :mp){
        sort(it.second.begin(),it.second.end());
        for(auto it2:it.second){
            ans[it.first.first-mini].push_back(it2);
        }
    }
    return ans;
    }
};