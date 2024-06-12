class Solution {
public:
    int titleToNumber(string columnTitle) {
        int x=columnTitle.length();
        int sum=0;
        for(int i=0;i<x-1;i++){
            sum=(sum+columnTitle[i]-64)*26;
        }
        sum+=columnTitle[x-1]-64;
        return sum;
    }
};