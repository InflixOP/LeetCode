class Solution {
    public:
        int maxScore(string s) {
            unordered_map<int,int> mp;
            unordered_map<int,int> mp1;
            int c=0;
            int c1=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='1')
                c1++;
                else
                c++;
            }
            if(c1==0||c==0)
            return s.length()-1;
            c=0;
            for(int i=0;i<s.length()-1;i++){
                if(s[i]=='0')
                c++;
                else
                c1--;
                mp[i]=c;
                mp1[i]=c1;
            }
            int maxi=INT_MIN;
            for(int i=0;i<s.length()-1;i++){
                maxi=max(maxi,mp[i]+mp1[i]);
            }
            return maxi;
        }
    };