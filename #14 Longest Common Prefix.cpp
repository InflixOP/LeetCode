class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int c=0;
        for(int i=0;i<strs[0].length();i++){
            if(strs[0][i]!=strs[strs.size()-1][i]){
                break;
            }else{
                c++;
            }
        }
        return strs[0].substr(0,c);
    }
};