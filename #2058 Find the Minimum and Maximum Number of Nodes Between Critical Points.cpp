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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       vector<int> index;
       int i=2;
        ListNode* p=head;
        p=p->next;
        while(p->next){
            if((p->val>p->next->val&&p->val>head->val)||(p->val<p->next->val&&p->val<head->val)){
                index.push_back(i);
            }
            i++;
            head=head->next;
            p=p->next;
        }
        if(index.size()<2){
            return {-1,-1};
        }
        int mini=100000;
        for(int i=1;i<index.size();i++){
            mini=min(mini,index[i]-index[i-1]);
        }
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(index[index.size()-1]-index[0]);
        return ans;
    }
};