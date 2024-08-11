class Solution {
public:
    bool validGrid(vector<vector<int>> &grid, int row, int col) {

        bitset<10> seen(0);

        for (int i = row; i <= row + 2; ++i) {

            for (int j = col; j <= col + 2; ++j) {

                int num = grid[i][j];

                // Check The Conditions.
                if (num > 9 or num < 1 or seen[num] == 1) return false;

                seen[num] = 1;
            }
        }

        return true;
    }

    bool isMagicSquare(vector<vector<int>> &grid, int row, int col) {

        if (validGrid(grid, row, col) == false) return false;

        // Standard Sum.
        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];

        // Check For Each Row Sum.

        for (int i = 0; i < 3; ++i) {

            int rowSum = grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2];
            if (rowSum != sum) return false;
        }

        // Check For Each Column Sum.

        for (int i = 0; i < 3; ++i) {

            int colSum = grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i];
            if (colSum != sum) return false;
        }

        // Check For 135° Diagonal Sum.
        
        int diagonalSum1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        if (diagonalSum1 != sum) return false;

        // Check For 45° Diagonal Sum.

        int diagonalSum2 = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];
        if (diagonalSum2 != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid) {
        
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int row = 0; row <= m - 3; ++row) {

            for (int col = 0; col <= n - 3; ++col)
                if (isMagicSquare(grid, row, col) == true) ++ans;
        }

        return ans;
    }
};