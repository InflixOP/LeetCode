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
    ListNode* oddEvenList(ListNode* head) {
        if(!head){
            return 0;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* e=head->next;
        while (even && even->next) {
            odd->next=even->next;
            odd=even->next;
            even->next=odd->next;
            even=odd->next;
}

        odd->next=e;
        return head;
    }
};