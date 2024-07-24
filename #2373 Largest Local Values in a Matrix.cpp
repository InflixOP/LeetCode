class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int nRows = grid.size();
        int nCols = grid[0].size();

        std::vector<std::vector<int>> result(nRows - 2,
                                             std::vector<int>(nCols - 2));

        auto findLargest = [&grid](int row, int col) {
            int best = grid[row][col];
            for (int i = row; i < row + 3; ++i) {
                for (int j = col; j < col + 3; ++j) {
                    best = std::max(best, grid[i][j]);
                }
            }
            return best;
        };

        for (int row = 0; row < nRows - 2; ++row) {
            for (int col = 0; col < nCols - 2; ++col) {
                result[row][col] = findLargest(row, col);
            }
        }

        return result;
    }
};