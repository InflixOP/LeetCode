class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<=n;i++){
            string s1="";
            for(int j=s.length()-1;j>=0;j--){
                if(s[j]=='1')
                s1+='0';
                else
                s1+='1';
            }
        s=s+"1"+s1;
        }
        return s[k-1];
    }
};