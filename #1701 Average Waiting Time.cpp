class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum=0;
        int prev=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i][0]<prev){
            sum+=customers[i][1]+prev-customers[i][0];
            prev+=customers[i][1];
            }
            else{
            sum+=customers[i][1];
            prev=customers[i][0]+customers[i][1];
            }
        }
        return sum/customers.size();
    }
};