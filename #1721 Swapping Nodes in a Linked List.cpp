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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode* q=head;
        while(q){
            n++;
            q=q->next;
        }
        if(n==1)
        return head;
        q=head;
        ListNode* s=head;
        for(int i=1;i<k;i++){
            q=q->next;
        }
        for(int i=1;i<n-k+1;i++){
            s=s->next;
        }
        int temp=q->val;
        q->val=s->val;
        s->val=temp;

        return head;
    }
};