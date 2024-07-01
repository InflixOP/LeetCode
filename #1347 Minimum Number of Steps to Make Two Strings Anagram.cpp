class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m;
        for(auto ele:s){
            m[ele]++;
        }
        int ans=0;
        for(auto ele:t){
            if(!m[ele])
                ans++;
            else{
                m[ele]--;
            }
        }
        return ans;
    }
};