class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                c++;
                maxi=max(maxi,c);
            }
            
            else if(s[i]==')'){
                c--;
            }
        }
        return maxi;
    }
};