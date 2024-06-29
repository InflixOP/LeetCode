/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
   TreeNode* func(ListNode* p, int i, int j){
        if (i > j) return NULL;
        ListNode* q=p;
        int m = (i+j)/2;
       int a=m;
       while(a>0){
           q=q->next;
           a--;
       }
        TreeNode* root = new TreeNode(q->val);

        root->left = func(p,i,m-1);
        root->right = func(p,m+1,j);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n=0;
        ListNode* p=head;
        while(p){
            n++;
            p=p->next;
        }
        TreeNode* root=func(head,0,n-1);
        return root;
    }

};