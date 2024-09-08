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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* p=head;
        vector<ListNode*> ans;
        while(p){
            n++;
            p=p->next;
        }
        p=head;
        if(k>n){
            while(k>0){
                if(p){
                ListNode* n1=new ListNode(p->val);
                 ans.push_back(n1);
                p=p->next;
                }else
                ans.push_back(nullptr);
                k--;
            }
            return ans;
        }
        ListNode* q=head;
        while(k>0){
        int size=0;
        if(n%k==0)
        size=n/k;
        else
        size=n/k+1;
        k--;
        n=n-size;
        for(int i=1;i<=size-1;i++){
            p=p->next;
        }
        q=p->next;
        p->next=nullptr;
        ans.push_back(head);
        head=q;
        p=head;
        }
        return ans;
    }
};