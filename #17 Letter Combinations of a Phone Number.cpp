class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> m;
        m[2] = {'a', 'b', 'c'};
        m[3] = {'d', 'e', 'f'};
        m[4] = {'g', 'h', 'i'};
        m[5] = {'j', 'k', 'l'};
        m[6] = {'m', 'n', 'o'};
        m[7] = {'p', 'q', 'r', 's'};
        m[8] = {'t', 'u', 'v'};
        m[9] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        string current;
        if (digits.empty()) {
            return ans;
        }
        generateCombinations(ans, m, digits, 0, current);
        return ans;
    }
    void generateCombinations(vector<string>& ans, unordered_map<int, vector<char>>& m, string& digits, int index, string& current) {
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for (char c : m[digit]) {
            current.push_back(c);
            generateCombinations(ans, m, digits, index + 1, current);
            current.pop_back();
        }
    }
};
