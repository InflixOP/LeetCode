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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return nullptr;
        }
        ListNode* p=head;
        int n=0;
        while(p){
            n++;
            p=p->next;
        }
        p=head;
        k=k%n;
        int n1=n;
        while(n1>1){
            n1--;
            p=p->next;
        }
        if(k==0)
        return head;
        p->next=head;
        ListNode* q=head;
        for(int i=1;i<n-k;i++){
            q=q->next;
        }
        head=q->next;
        q->next=nullptr;
        return head;
    }
};