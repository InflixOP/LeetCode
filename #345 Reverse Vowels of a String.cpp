class Solution {
public:
    string reverseVowels(string s) {
        vector<int> index;
        vector<char> vowel;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                vowel.push_back(s[i]);
                index.push_back(i);
            }
        }
        for(int i=0;i<index.size();i++){
            s[index[i]]=vowel[vowel.size()-1-i];
        }
        return s;
    }
};