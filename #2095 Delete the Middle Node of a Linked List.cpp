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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* p=head;
        int mid=0;
        while(p){
            mid++;
            p=p->next;
        }
        if(head==nullptr){
            return head;
        }if(mid==1){
            return {};
        }
    mid=mid/2+1;
    p=head;
    ListNode* q=nullptr;
    for(int i=1;i<mid;i++){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    delete p;
    return head;
    }
};