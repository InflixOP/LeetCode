class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        return stoi(s);
    }
};