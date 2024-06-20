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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n=preorder.size();
    stack<TreeNode *> st;
    TreeNode *p,*t;
    TreeNode* root=new TreeNode;
    int i=0;
    root->val=preorder[i++];
    root->left=root->right=NULL;
    p=root;
    while (i<n)
    {
       if(p->val>preorder[i])
       {
        t=new TreeNode;
        t->val=preorder[i++];
        t->left=t->right=NULL;
        p->left=t;
        st.emplace(p);
        p=t;
       }
       else if(p->val<preorder[i] && st.empty()?1:(st.top()->val>preorder[i]?1:0))
       {
        t=new TreeNode;
        t->val=preorder[i++];
        t->left=t->right=NULL;
        p->right=t;
        p=t;
       }
       else
        {
            p=st.top();
            st.pop();
        }
    }
        return root;
    }
};