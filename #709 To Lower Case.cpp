class Solution {
public:
    string toLowerCase(string s) {
         for (char &c:s) {
        c = std::tolower(c);
    }
        return s;
    }
};