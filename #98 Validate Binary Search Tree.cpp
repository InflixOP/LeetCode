class Solution {
public:
    bool isValidBST(TreeNode* root, long min = LONG_MIN, long max = LONG_MAX){ 
       if(root == NULL)
           return true;
       if((root->val >= max) || (root->val <= min))
           return false;
       else
           return isValidBST(root->left,min,root->val) &&  isValidBST(root->right,root->val,max);
   }
 };