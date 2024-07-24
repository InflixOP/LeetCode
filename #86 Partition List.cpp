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
    ListNode* partition(ListNode* head, int x) {
        ListNode* s=new ListNode();
        ListNode* b=new ListNode();
        ListNode* s1=s;
        ListNode* b1=b;
        while(head) {
            if(head->val<x) {
                s1->next=head;
                s1=s1->next;
            }else{
                b1->next=head;
                b1=b1->next;
            }
            head=head->next;
        }
        s1->next=b->next;
        b1->next = nullptr;
        return s->next;    
    }
};