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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p=head;
        if(p->val==0){
            p=p->next;
        }
        ListNode* q=nullptr;
        ListNode* r=nullptr;
        int value=0;
        while(p){
            if(p->val==0){
                ListNode* n=new ListNode(value);
                if(!q){
                    q=n;
                    r=q;
                }else{
                    q->next=n;
                    q=n;
                }
                value=0;
            }else{
                value+=p->val;
            }
            p=p->next;
        }
        return r;
    }
};