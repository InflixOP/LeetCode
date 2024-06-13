class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total=0;
        while(tickets[k]!=0){
            for(int i=0;i<tickets.size();i++){
                if(tickets[i]!=0){
                    tickets[i]=tickets[i]-1;
                    total++;
                }
                if(tickets[k]==0){
                    break;
                }
            }
        }
        return total;
    }
};