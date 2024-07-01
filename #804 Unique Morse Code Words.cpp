class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string, int> m;
        for (const string& word : words) {
            string s = "";
            for (char c : word) {
                s += morse[c - 'a'];
            }
            m[s]++;
        }
        return m.size();
    }
};