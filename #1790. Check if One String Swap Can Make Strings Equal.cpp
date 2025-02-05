class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s1.length();i++)
        mp[s1[i]]++;
        for(int i=0;i<s2.length();i++){
        if(!mp[s2[i]])
        return false;
        mp[s2[i]]--;
        }
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])
            c++;
        }
        if(c==1&&s1.length()==2)
        return false;
        if(c>2)
        return false;
        return true;
    }
};