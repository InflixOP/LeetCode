class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        string result = "";
        vector<bool> a(256, false); 
        for (char c : s) {
            m[c]--;   
            if (a[c]) {
                continue;
            }
            while (!result.empty() && c < result.back() && m[result.back()] > 0) {
                a[result.back()] = false;
                result.pop_back();
            }
            result += c;
            a[c] = true;
        }
        
        return result;
    }
};
