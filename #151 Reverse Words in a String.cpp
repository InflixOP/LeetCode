class Solution {
public:
    std::string reverseWords(std::string s) {
        trim_left(s);
        trim_right(s);
        int start = 0;
        std::vector<std::string> ans;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (i > start) {
                    std::string sub = s.substr(start, i - start);
                    ans.push_back(sub);
                }
                start = i + 1;
            }
        }
        if (start < s.size()) {
            std::string last_word = s.substr(start);
            ans.push_back(last_word);
        }
        std::reverse(ans.begin(), ans.end());
        std::string reversed_str = "";
        for (int i = 0; i < ans.size(); ++i) {
            reversed_str += ans[i];
            if (i < ans.size() - 1) {
                reversed_str += " ";
            }
        }
        return reversed_str;
    }

private:
    void trim_left(std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
        }));
    }

    void trim_right(std::string& s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }
};