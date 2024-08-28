class Solution {
public:
    bool island = false;
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m){
        if(grid1[i][j] != grid2[i][j]){
            island = false;
        }
        grid2[i][j] = 0;

        grid1[i][j] = 0;
        int a[] = {0, 0, 1, -1};
        int b[] = {1, -1, 0, 0};
        // traverse in all directions
        for(int k=0; k<4; k++){
            int x = i+a[k];
            int y = j+b[k];
            if(x >=0 && x< n && y>=0 && y<m && grid2[x][y] == 1 ){
                dfs(x, y, grid1, grid2, n, m);
                
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int n = grid2.size();
        int m = grid2[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1){
                    // assuming it is a subisland
                    island = true;
                    dfs(i, j, grid1, grid2, n, m);
                    // if dfs does not mark island false then increment count
                    if(island) count++;
                    
                }
            }
        }
        return count;
    }
};