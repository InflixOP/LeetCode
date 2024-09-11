class Solution {
public:
    int minBitFlips(int start, int goal) {
        int c=0;
        while(start!=0||goal!=0){
            cout<<start%2<<goal%2<<endl;
            if(start%2!=goal%2)
            c++;
            start=start/2;
            goal=goal/2;
        }
        return c;
    }
};