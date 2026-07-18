class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Flip rows if first element is 0
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        // Flip columns if needed
        for (int j = 1; j < n; j++) {
            int ones = 0;
            for (int i = 0; i < m; i++) {
                ones += grid[i][j];
            }

            if (ones < m - ones) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] ^= 1;
                }
            }
        }

        // Calculate score
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int val = 0;
            for (int j = 0; j < n; j++) {
                val = val * 2 + grid[i][j];
            }
            ans += val;
        }

        return ans;
    }
};