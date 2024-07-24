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
    int getDecimalValue(ListNode* head) {
        int n=0;
        ListNode* p=head;
        while(p){
            n++;
            p=p->next;
        }
        int sum=0;
        while(head){
            sum+=pow(2,n-1)*head->val;
            n--;
            head=head->next;
        }
        return sum;
    }
};