class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int bob=0;
        int alice=0;
        int i=0;
        int j=piles.size()-1;
        int c=0;
        while(i<j){
            if(c%2==0)
        {
            if(piles[i]>=piles[j])
            alice+=piles[i++];
            else
            alice+=piles[j--];
        }else{
             if(piles[i]>=piles[j])
            bob+=piles[i++];
            else
            bob+=piles[j--];
        }
        }
        return alice>bob;
    }
};