class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        vector<pair<int,int>> v(n,{-1,-1});
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                v[i].first = max(v[i].first,grid[i][j]);
                v[j].second = max(v[j].second,grid[i][j]);
            }
        }
        for(int i=0,k=0; i<n; ++i,++k){
            for(int j=0; j<n; ++j)
                ans += min(v[i].first,v[j].second) - grid[i][j];
        }
        return ans;
    }
};