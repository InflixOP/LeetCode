class Solution {
public:
    
    void dfs(vector<vector<int>> &mat, int i, int j){
        int n = mat.size();
        if(i>=0 && j>=0 && i<n && j<n && mat[i][j]){
            mat[i][j] = 0;
            dfs(mat, i+1, j);
            dfs(mat, i-1, j);
            dfs(mat, i, j+1);
            dfs(mat, i, j-1);
        }
    }
    
    int regionsBySlashes(vector<string>& g) {
        int n = g.size();
        vector<vector<int>> mat(n*3 , vector<int>(n*3, 1));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(g[i][j] == '/'){
                    mat[i*3][j*3 + 2] = mat[i*3 + 1][j*3 + 1] = mat[i*3 + 2][j*3] = 0;
                }
                else if(g[i][j] == '\\'){
                    mat[i*3][j*3] = mat[i*3 + 1][j*3 + 1] = mat[i*3 + 2][j*3 + 2] = 0;
                }
            }
        }
        int count  = 0, N = n*3;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(mat[i][j]){
                    count++;
                    dfs(mat, i, j);
                }
            }
        }
        return count;
    }
};