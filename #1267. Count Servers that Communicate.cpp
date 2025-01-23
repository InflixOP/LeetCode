class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,bool> mp;
        unordered_map<int,bool> mp1;
        for(int i=0;i<grid.size();i++){
            int c=0;
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1){
                    c++;
                }
                if(c>1){
                    mp[i]=true;
                    break;
                }
            }
        }
         for(int i=0;i<grid[0].size();i++){
            int c=0;
            for(int j=0;j<grid.size();j++)
            {
                if(grid[j][i]==1){
                    c++;
                }
                if(c>1){
                    mp1[i]=true;
                    break;
                }
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if((mp[i]||mp1[j])&&grid[i][j]==1)
                ans++;
            }
        }
        return ans;
    }
};