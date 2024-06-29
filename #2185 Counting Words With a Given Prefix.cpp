class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
       int ans=0;
        int n=pref.length();
        for(int i=0;i<words.size();i++){
            if(words[i].substr(0,n)==pref)
                ans++;
        }
        return ans;
    }
};