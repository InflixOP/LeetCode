class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        if(s[n-1]==' '){
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                n=i;
                break;
            }
        }for(int i=n-1;i>=0;i--){

            if(s[i]==' '){
                return n-i;
            }
        }
        return n+1;
        }else{
        for(int i=n-1;i>=0;i--){

            if(s[i]==' '){
                return n-i-1;
            }
        }}
        return n;
    }
};