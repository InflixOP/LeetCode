class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int common = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    ans++;
                    if(i<n-1 && grid[i+1][j]==1){
                        common++;
                    }
                    if(i>0 && grid[i-1][j]==1){
                        common++;
                    }
                    if(j<m-1 && grid[i][j+1]==1){
                        common++;
                    }
                    if(j>0 && grid[i][j-1]==1){
                        common++;
                    }
                }
            }
        }
        return (4*ans)-common;
    }
};