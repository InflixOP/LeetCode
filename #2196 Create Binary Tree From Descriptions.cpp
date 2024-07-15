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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> child;
        for (auto& a:descriptions) {
            int p=a[0],c=a[1],l=a[2];
            child.insert(c);
            if (mp.find(p)==mp.end()) {
                mp[p]=new TreeNode(p);
            }
            if (mp.find(c)==mp.end()) {
                mp[c]=new TreeNode(c);
            }
            if (l==1) {
                mp[p]->left=mp[c];
            } else {
                mp[p]->right=mp[c];
            }
        }
        int root=-1;
        for(auto& a:descriptions) {
            if(child.find(a[0])==child.end()){
                root=a[0];
                break;
            }
        }
        return mp[root];
    }
};