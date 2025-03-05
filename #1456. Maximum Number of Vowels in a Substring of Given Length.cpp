class Solution {
    public:
        int maxVowels(string s, int k) {
          int c=0,ans=0;
          int n=s.length();
          for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            c++;
          }  
            ans=c;
          for(int i=k,j=0;i<n;i++,j++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            c++;
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
            c--;
            ans=max(ans,c);
          }
          return ans;
        }
    };