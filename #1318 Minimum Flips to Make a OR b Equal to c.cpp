class Solution {
public:
    int minFlips(int a, int b, int c) {
        int n=0;
        while(c>0||b>0||a>0){
            int i=a%2;
            int j=b%2;
            int k=c%2;
            a/=2;
            b/=2;
            c/=2;
            if(i==1&&j==1&&k==0){
                n+=2;
            }
            else if((i|j)!=k){
                n++;
                }
        }
        return n;
    }
};