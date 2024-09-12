class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int c=0;
        unordered_map<char,int> mp;
        for(char ele:allowed)
        mp[ele]++;
        for(int i=0;i<words.size();i++){
            int n=words[i].length();
            for(char c1:words[i]){
                if(mp[c1])
                n--;
            }
            if(n==0)
            c++;
        }
        return c;
    }
};