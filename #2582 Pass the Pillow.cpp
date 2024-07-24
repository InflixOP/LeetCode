class Solution {
public:
    int passThePillow(int n, int time) {
        int i=1;
        int j=0;
        while(time>0&&(i<=n&&i>0)){
            if((j==1||i==n)&&i>1){
                i--;
                time--;
                j=1;
                continue;
            }
            j=0;
            i++;
            time--;
            continue;
        }
        return i;
    }
};