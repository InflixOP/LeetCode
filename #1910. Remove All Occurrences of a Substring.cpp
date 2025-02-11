class Solution {
public:
    string removeOccurrences(string s, string part) {
        string resultStack;
        int targetLength = part.size();
        char targetEndChar = part.back();

        for (char currentChar : s) {
            resultStack.push_back(currentChar);

            if (currentChar == targetEndChar && resultStack.size() >= targetLength) {
                if (resultStack.substr(resultStack.size() - targetLength) == part) {
                    resultStack.erase(resultStack.size() - targetLength);
                }
            }
        }
        return resultStack;
    }
};
