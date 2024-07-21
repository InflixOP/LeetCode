class Solution {
public:
    string losingPlayer(int x, int y) {
        int i=0;
        while(x>0&&y>3){
            i++;
            x=x-1;
            y=y-4;
        }
        if(i%2==0)
        return "Bob";
        return "Alice";
    }
};