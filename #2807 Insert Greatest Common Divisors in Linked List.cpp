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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p=head;
        if(!head){
            return {};
        }
        if(!head->next)
        return head;
        int ans=0;
        while(p->next){
        ans=__gcd(p->val,p->next->val);
        ListNode* n=new ListNode(ans);
        ListNode* q=p->next;
        p->next=n;
        n->next=q;
        p=q;
    }
    return head;
    }
};