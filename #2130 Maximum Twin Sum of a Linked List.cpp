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
    int pairSum(ListNode* head) {
        vector<int> value;
        while(head){
            value.push_back(head->val);
            head=head->next;
        }
        int maxi=-87394563;
        for(int i=0;i<value.size()/2;i++){
            maxi=max(maxi,value[i]+value[value.size()-1-i]);
        }
        return maxi;
    }
};