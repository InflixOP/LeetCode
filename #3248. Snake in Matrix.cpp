class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int a=0,b=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]=="RIGHT"){
                b++;
            }
            else if(commands[i]=="DOWN"){
                a++;
            }
            else if(commands[i]=="UP"){
                a--;
            }
            else{
                b--;
            }
        }
        return (a*n)+b;
    }
};