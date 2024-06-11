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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int carry=0;
        l1=reverseList(l1);
        l2=reverseList(l2);
        ListNode* ans=nullptr;
        ListNode* f=nullptr;
        while(l1&&l2){
            ListNode* n=new ListNode((l1->val+l2->val+carry)%10);
            if(!ans){
                ans=n;
                f=ans;
            }else{
                ans->next=n;
                ans=ans->next;
            }
            carry=(l1->val+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
            
        }
        while(l1){
            ListNode* n=new ListNode((l1->val+carry)%10);
            if(!ans){
                ans=n;
                f=ans;
            }else{
                ans->next=n;
                ans=ans->next;
            }
            carry=(l1->val+carry)/10;
            l1=l1->next;
        }
        while(l2){
            ListNode* n=new ListNode((l2->val+carry)%10);
            if(!ans){
                ans=n;
                f=ans;
            }else{
                ans->next=n;
                ans=ans->next;
            }
            carry=(l2->val+carry)/10;
            l2=l2->next;
        }

        if(carry!=0){
            ListNode* n=new ListNode(carry);
            if(!ans){
                ans=n;
                f=ans;
            }else{
                ans->next=n;
                ans=ans->next;
            }
        }
                f=reverseList(f);
        return f;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* p=nullptr;
        ListNode* q=nullptr;
        while(head){
            q=p;
            p=head;
            head=head->next;
            p->next=q;
        }
        head=p;
        return head;
    }
};