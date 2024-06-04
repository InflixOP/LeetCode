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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p=head;
        ListNode* q=head;
        head=head->next;
        while(head){
            int temp;
            temp=q->val;
            q->val=head->val;
            head->val=temp;
            if(!head->next){
                break;
            }
            q=q->next->next;
            head=head->next->next;
        }
        return p;
    }
};