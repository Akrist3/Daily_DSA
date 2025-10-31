class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> result(n, -1);
        
        for (int start = 0; start < n; start++) {
            int col = start;
            for (int row = 0; row < m; row++) {
                int nextCol = col + grid[row][col];
                // Check boundary or V shape
                if (nextCol < 0 || nextCol >= n || grid[row][col] != grid[row][nextCol]) {
                    col = -1;
                    break;
                }
                col = nextCol;
            }
            result[start] = col;
        }
        
        return result;
    }
};
