class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans=0;
        for (int i=0;i<s.length();i++) {
            for (int j=0;j<t.length();j++) {
                if (t[j]==s[i]) {
                    ans+=abs(i-j);
                    break;
                }
            }
        }
        return ans;
    }
};