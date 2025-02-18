class Solution {
    public:
        int maxScore(string s) {
            int c=0,c1=0,maxi=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='1')
                c1++;
            }
            for(int i=0;i<s.length()-1;i++){
                if(s[i]=='0')
                c++;
                else
                c1--;
                maxi=max(maxi,c+c1);
            }
            return maxi;
        }
    };