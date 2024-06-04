class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* p = reverseList(head);
        ListNode* q = p;
        int carry = 0;
        while (q) {
            int sum = q->val * 2 + carry;
            q->val = sum % 10;
            carry = sum / 10;
            q = q->next;
        }
        p=reverseList(p);
        if (carry) {
            ListNode* r = new ListNode(carry);
            r->next = p;
            p = r;
        }
        return p;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
};
