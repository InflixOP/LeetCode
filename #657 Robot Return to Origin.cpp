class Solution {
public:
    bool judgeCircle(string moves) {
        int ud=0;
        int lr=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='U')
            ud++;
            else if(moves[i]=='D')
            ud--;
            else if(moves[i]=='R')
            lr++;
            else
            lr--;
        }
        if(ud==0&&lr==0)
        return true;
        return false;
    }
};