class Solution {
public:
    int minimumLength(string s) {
        int ans=s.length();
        if(s.length()<3)
        return s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto ele:mp){
            if(ele.second>=3){
                if(ele.second%2==0)
                ans=ans-(ele.second-2);
                else
                ans=ans-(ele.second-1);
            }
        }
        return ans;
    }
};