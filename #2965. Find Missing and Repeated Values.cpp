class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int> ans;
            unordered_map<int,int> mp;
            int n=grid.size();
            for(int i=1;i<=n*n;i++){
                mp[i]++;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<grid[0].size();j++){
                    mp[grid[i][j]]++;
                    if(mp[grid[i][j]]==3)
                    ans.push_back(grid[i][j]);
                }
            }
            for(auto ele:mp){
                if(ele.second==1)
                ans.push_back(ele.first);
            }
            return ans;
        }
    };