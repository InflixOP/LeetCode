class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int empty=0;
        while(numBottles>0){
            ans=ans+numBottles;
            empty+=numBottles;
            numBottles=empty/numExchange;
           empty%=numExchange;
        }
        return ans;
    }
};