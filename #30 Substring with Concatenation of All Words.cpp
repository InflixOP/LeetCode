class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<string> ans;
        vector<int> final;
        if (words.empty()) return final;

        int n1= words[0].length();
        int n = n1 * words.size();
        if (s.length() < n) return final;
        permute(0,words.size(),ans,words);
        for(int i=0;i<=s.length()-n;i++){
            for(int j=0;j<ans.size();j++){
                if(s.substr(i,n)==ans[j]){
                    final.push_back(i);
                    break;
                }
            }
        }   
        return final;
    }
    void permute(int l,int h,vector<string> &ans,vector<string> words){
        if(l==h){
            string s;
            for(int i=0;i<h;i++){
                s=s+words[i];
            }
            ans.push_back(s);
        }
        for(int i=l;i<h;i++){
            swap(words[l],words[i]);
            permute(l+1,h,ans,words);
            swap(words[l],words[i]);
        }
    }
};