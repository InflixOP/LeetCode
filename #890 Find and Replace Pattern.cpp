class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for (const auto& word : words) {
            if (word.size() != pattern.size()) continue;
            
            unordered_map<char, char> map1;
            unordered_map<char, bool> mapped;
            bool match = true;
            
            for (int i = 0; i < pattern.size(); ++i) {
                char p = pattern[i];
                char w = word[i];
                
                if (map1.find(p) == map1.end()) {
                    if (mapped[w]) {
                        match = false;
                        break;
                    }
                    map1[p] = w;
                    mapped[w] = true;
                } else {
                    if (map1[p] != w) {
                        match = false;
                        break;
                    }
                }
            }
            
            if (match) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
