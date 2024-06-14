class Solution {
private:
    ListNode *head;
    int size=0;

    int len(ListNode* head){
        ListNode* mover=head;
        int n=0;
        while(mover){
            n++;
            mover=mover->next;
        }
        return n;
    }
public:
    
    Solution(ListNode* head) {
        this->head=head;
        size=len(head);
    }
    
    int getRandom() {
        int move=rand()%size;
        ListNode* mover=head;
        while(move){
            mover=mover->next;
            move--;
        }
        return mover->val;
    }
};