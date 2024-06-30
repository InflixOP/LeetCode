class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto ele : nums) {
            m[ele]++;
        }
        vector<pair<int, int>> freqVec(m.begin(), m.end());
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        vector<int> ans;
        for (int i = 0; i < k && i < freqVec.size(); ++i) {
            ans.push_back(freqVec[i].first);
        }
        return ans;
    }
};