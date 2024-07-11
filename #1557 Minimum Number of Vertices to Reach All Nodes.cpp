class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans(n,0);
        for (auto& edge:edges) {
            ans[edge[1]]++;
        }
        vector<int> result;
        for (int i=0;i<n;i++) {
            if (ans[i]==0) {
                result.push_back(i);
            }
        }
        return result;
    }
};