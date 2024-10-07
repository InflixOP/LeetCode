class Solution {
public:
    int minLength(string s) {
        int n=s.length();
        int i=0;
        while(s[i]){
            if((s[i]=='A'&&s[i+1]=='B')||s[i]=='C'&&s[i+1]=='D'){
                s.erase(i,2);
                i=0;
            }else
            i++;
        }
        return s.length();
    }
};