class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        string ans;
        while(i<word1.length()&&i<word2.length()){
            ans+=word1[i];
            ans+=word2[i];
            i++;
        }
        for(;i<word1.length();i++){
            ans+=word1[i];
        }
        for(;i<word2.length();i++){
            ans+=word2[i];
        }
        return ans;
    }
};