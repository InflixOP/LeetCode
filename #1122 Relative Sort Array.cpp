class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i = 0; i < arr1.size(); i++) m[arr1[i]]++;
        for(int i = 0; i < arr2.size(); i++) {
            if(m.find(arr2[i]) != m.end()) {
                int count = m[arr2[i]];
                while (count-- > 0) {
                    ans.push_back(arr2[i]);
                }
                m.erase(arr2[i]);
            }
        }
        vector<pair<int, int>> remaining;
        for(auto& pair : m) {
            remaining.push_back(pair);
        }
        sort(remaining.begin(), remaining.end());
        for(auto& pair : remaining) {
            int num = pair.first;
            int count = pair.second;
            while (count-- > 0) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
