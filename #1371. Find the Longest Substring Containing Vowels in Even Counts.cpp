class Solution {
public:
    int findTheLongestSubstring(string s) {
        const string vowels = "aeiou";
        int ans = 0, prefix = 0;
        unordered_map<int, int> mp{{0,-1}};

        for(int i = 0; i<s.length(); i++){
            const int index = vowels.find(s[i]);
            if(index != -1){
                prefix ^= 1<<index;
            }
            if(!mp.contains(prefix)){
                mp[prefix] = i;
            }
            ans = max(ans, i-mp[prefix]);
        }
        return ans;
    }
};