class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n = groupSizes.size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[groupSizes[i]].push_back(i);
        }

        for(auto it : mp) {
            vector<int> v;
            int size = it.first;
            vector<int> temp = it.second;
            int n = temp.size()/size;
            int index = 0;
            for(int i = 0; i < n; i++) {
                vector<int> v;
                for(int j = 0; j < size; j++) {
                    v.push_back(temp[index]);
                    index++;
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};