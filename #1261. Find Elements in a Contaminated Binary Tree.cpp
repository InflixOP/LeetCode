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
class FindElements {
public:
    TreeNode* h;
    queue<TreeNode*> q;
    FindElements(TreeNode* root) {
        h=root;
        h->val=0;
        q.push(h);
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            if(a->left){
                a->left->val=2* a->val+1;
                q.push(a->left);
            }
            if(a->right){
                a->right->val=2* a->val+2;
                q.push(a->right);
            }
        }
    }
    
    bool find(int target) {
        q.push(h);
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            if(a->val==target)
            return true;
            if(a->left)
            q.push(a->left);
            if(a->right)
            q.push(a->right);
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */