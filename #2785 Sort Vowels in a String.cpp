class Solution {
public:
    string sortVowels(string s) {
        vector<int> index;
        vector<char> vowel;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                index.push_back(i);
                vowel.push_back(s[i]);
            }
        }
        sort(vowel.begin(),vowel.end());
        for(int i=0;i<index.size();i++){
            s[index[i]]=vowel[i];
        }
        return s;
    }
};