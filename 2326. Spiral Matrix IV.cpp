/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullheadtr) {}
 *     ListNode(int x) : val(x), next(nullheadtr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int t=0,l=0,r=n-1;
        int b=m-1;
        while(head){
            for(int i=l;i<=r&&head;i++){
                ans[t][i]=head->val;
                head=head->next;
            }
            t++;
            for(int i=t;i<=b&&head;i++){
                ans[i][r]=head->val;
                head=head->next; 
            }
            r--;
            for(int i=r;i>=l&&head;i--){
                ans[b][i]=head->val;
                head=head->next; 
            }
            b--;
            for(int i=b;i>=t&&head;i--){
                ans[i][l]=head->val;
                head=head->next; 
            }
            l++;
        }
        return ans;
    }
};