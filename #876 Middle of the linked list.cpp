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
    ListNode* middleNode(ListNode* head) {
        ListNode* p=head;
        int mid=0;
        while(p){
            mid++;
            p=p->next;
        }
        if(head==nullptr){
            return head;
        }if(mid==1){
            return head;
        }
    mid=mid/2+1;
    p=head;
    for(int i=1;i<mid;i++){
        p=p->next;
    }
    return p;
    }
};