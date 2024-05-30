class Solution {
public:
    bool isPalindrome(int x) {
        long n=x;
        long d=0,r=0;
        while(n>0){
            d=n%10;
            r=r*10+d;
            n=n/10;
        }
        if(r==x){
            return true;
        }else{
            return false;
        }
    }
};