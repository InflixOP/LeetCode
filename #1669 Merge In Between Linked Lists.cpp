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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* q=list2;
        ListNode* p=list1;
        while(q->next){
            q=q->next;
        }
        for(int i=0;i<a-1;i++){
            p=p->next;
        }
        ListNode* r=list1;
        for(int i=0;i<b;i++){
            r=r->next;
        }
        p->next=list2;
        q->next=r->next;
        r->next=nullptr;
        return list1;
    }
};