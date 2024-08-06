class neighborSum {
public:
    vector<vector<int>> mat;
    neighborSum(vector<vector<int>>& grid) {
        mat=grid;
    }
    
    int adjacentSum(int value) {
        int r=0;
        int c=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==value){
                    r=i;
                    c=j;
                    break;
                }
            }
        }
        int ans=0;
        if(r+1<mat.size())
        ans+=mat[r+1][c];
        if(r-1>=0)
        ans+=mat[r-1][c];
        if(c+1<mat[0].size())
        ans+=mat[r][c+1];
        if(c-1>=0)
        ans+=mat[r][c-1];
        return ans;
    }
    
    int diagonalSum(int value) {
         int r=0;
        int c=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==value){
                    r=i;
                    c=j;
                    break;
                }
            }
        }
        int ans=0;
        if(r+1<mat.size()&&c+1<mat[0].size())
        ans+=mat[r+1][c+1];
        if(r-1>=0&&c-1>=0)
        ans+=mat[r-1][c-1];
        if(c+1<mat[0].size()&&r-1>=0)
        ans+=mat[r-1][c+1];
        if(c-1>=0&&r+1<mat.size())
        ans+=mat[r+1][c-1];
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */