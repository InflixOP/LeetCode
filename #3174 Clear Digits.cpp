class Solution {
public:
    string clearDigits(string& s) {
        int k=0;
        for(int i=0;i<s.size();i++) {
            if (s[i]>'9'){
                s[k++]=s[i];
            }
            else {
                k--;
            }
        }
        s.resize(k);
        return move(s);
    }
};