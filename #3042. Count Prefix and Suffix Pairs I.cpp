class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int c=0;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[j].length()<words[i].length())
                continue;
                string p=words[j].substr(0,words[i].length());
                string s=words[j].substr(words[j].length()-words[i].length());
                if(p==words[i]&&s==words[i])
                c++;
            }
        }
        return c;
    }
};