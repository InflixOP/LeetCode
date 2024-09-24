class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        unordered_set<int> s1;
        for(int i = 0; i < n; i++) {
            int num = arr1[i];
            while (num) {
                s1.insert(num);
                num /= 10;
            }
        }
        int maxi = INT_MIN;
        for(int j = 0; j < arr2.size(); j++) {
            int x = arr2[j];
            string s2 = to_string(x);
            string ans = "";
            for(int k = 0; k < s2.size(); k++) {
                ans = ans + s2[k];
                int y = stoi(ans);
                if(s1.find(y) != s1.end()) {
                    int le = ans.size();
                    maxi = max(maxi,le);
                }  
                else {
                    break;
                }
            }
        }
        return (maxi == INT_MIN) ? 0 : maxi;
    }
};