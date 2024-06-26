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
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int,TreeNode*>m;
        TreeNode* root,*ptr;
        int i=0;
        string num="";
        while(i<traversal.size() && traversal[i]!='-'){
            num+=traversal[i];
            i++;
        }
        
        ptr =new TreeNode(stoi(num));
        m[0]=ptr;
        root=ptr;
        
        while(i<traversal.size()){
            int dash=0;
            string s="";
            while(traversal[i]=='-'){
                dash++;
                i++;
            }
            
            while(i<traversal.size() && traversal[i]!='-'){
                s+=traversal[i];
                i++;
            }
            
            auto ele=new TreeNode(stoi(s));
            if(!m[dash-1]->left)m[dash-1]->left=ele;
            else m[dash-1]->right=ele;
            
            m[dash]=ele;
        }
        
        return root;
    }
};