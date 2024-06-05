class Solution {
public:
ListNode* reverseBetween(ListNode* head, int left, int right) {
if (left == right)
return head;

ListNode dummy(0);
dummy.next = head;
ListNode* pre = &dummy;

for (int i = 0; i < left - 1; ++i)
pre = pre->next;

ListNode* cur = pre->next;
ListNode* nextNode = nullptr;

for (int i = 0; i < right - left; ++i) {
nextNode = cur->next;
cur->next = nextNode->next;
nextNode->next = pre->next;
pre->next = nextNode;
}

return dummy.next;
}
};
