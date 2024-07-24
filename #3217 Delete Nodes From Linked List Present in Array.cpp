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
    ListNode* modifiedList(vector<int>& v, ListNode* head) {
        ListNode *p=new ListNode(-1);
        ListNode *q=p;
        set<int>s;
        for(auto i:v)
            s.insert(i);
        while(head!=NULL) {
            if(s.find(head->val)==s.end()) {
                q->next=head;
                q=q->next;
            }
            head=head->next;
        }
        q->next=NULL;
        return p->next;
    }
};