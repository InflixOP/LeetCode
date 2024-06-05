class Solution {
public:
ListNode* mergeKLists(vector<ListNode*>& lists) {
ListNode p(0);
ListNode *last = &p;

while (true) {
int smallestIndex = -1;
for (int i = 0; i < lists.size(); ++i) {
if (lists[i] != nullptr && (smallestIndex == -1 || lists[i]->val < lists[smallestIndex]->val)) {
smallestIndex = i;
}
}
if (smallestIndex == -1) break;

last->next = lists[smallestIndex];
last = last->next;
lists[smallestIndex] = lists[smallestIndex]->next;
}

return p.next;
}
};
