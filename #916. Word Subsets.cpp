class Solution {
public:
    inline bool each_greaterEq(array<int, 26>& s, array<int, 26>& t){
        for(int i=0; i<26; i++)
            if (s[i]<t[i]) return 0;
        return 1;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        array<int, 26> maxfreq={0};
        for(auto& w: words2){
            array<int, 26> fw={0};
            for(char c: w) 
                fw[c-'a']++;
            for (int i=0; i<26; i++)
                maxfreq[i]=max(maxfreq[i], fw[i]);
        }
        vector<string> ans;
        ans.reserve(words1.size());
        for(auto& w: words1){
            array<int, 26> fw={0};
            for(char c: w) 
                fw[c-'a']++;
            if (each_greaterEq(fw, maxfreq))
                ans.push_back(w);
        }
        return ans;
    }
};