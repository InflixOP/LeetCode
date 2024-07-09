class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* node = head;
        ListNode* nxtGreater = removeNodes(node->next);

        node->next = nxtGreater;
        if (nxtGreater == nullptr || node->val >= nxtGreater->val) {
            return node;
        }
        return nxtGreater;
    }
};