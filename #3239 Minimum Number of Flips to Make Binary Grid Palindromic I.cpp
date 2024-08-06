class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        auto rowFlips=[&](int row) {
            int flips=0;
            for (int j=0;j<n/2;++j) {
                if(grid[row][j]!=grid[row][n-1-j]) {
                    ++flips;
                }
            }
            return flips;
        };
        auto colFlips=[&](int col) {
            int flips=0;
            for (int i=0;i<m/2;++i) {
                if (grid[i][col]!=grid[m-1-i][col]) {
                    ++flips;
                }
            }
            return flips;
        };
        int totalRowFlips = 0;
        for (int i=0;i<m;++i) {
            totalRowFlips += rowFlips(i);
        }
        int totalColFlips=0;
        for (int j=0;j<n;++j) {
            totalColFlips+=colFlips(j);
        }
        return min(totalRowFlips,totalColFlips);
    }
};
