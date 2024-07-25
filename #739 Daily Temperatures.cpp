class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tp) {
        stack<int> s;
        vector<int> ans;
        
        for (int i = tp.size() - 1; i >= 0; i--) {
            if (s.empty()) {
                s.push(i);
                ans.push_back(0);
            } else {
                while (!s.empty() && tp[s.top()] <= tp[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    s.push(i);
                    ans.push_back(0);
                } else {
                    ans.push_back(s.top() - i);
                    s.push(i);
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};