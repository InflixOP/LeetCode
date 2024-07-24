class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int c=0,max=0;
        for(auto s:sentences){
            c=0;
            for(auto x:s){
                if(x==' ')
                c++;
            }
            if(++c>max)
            max=c;
        }
        return max;
    }
};