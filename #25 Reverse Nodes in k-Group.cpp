class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        int n = k;
        if (!head) {
            return nullptr;
        }
        if (k == 1 || !head->next) {
            return head;
        }
        int num = 0;
        while (p) {
            num++;
            p = p->next;
        }
        p = head;
        ListNode* q = nullptr;
        ListNode* r = nullptr;
        ListNode* prevGroupEnd = nullptr;
        ListNode* result = nullptr;
        int c = 0;
        for (int i = 0; i < num / k; i++) {
            ListNode* groupStart = p;
            while (k > 0) {
                r = q;
                q = p;
                p = p->next;
                q->next = r;
                k--;
            }
            if (result == nullptr) {
                result = q;
            }
            if (prevGroupEnd != nullptr) {
                prevGroupEnd->next = q;
            }
            prevGroupEnd = groupStart;
            prevGroupEnd->next = p;
            k = n;
            q = nullptr;
        }
        return result;
    }
};
