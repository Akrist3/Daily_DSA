class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        vector<vector<int>> up(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    left[i][j] = (j > 0 ? left[i][j - 1] : 0) + 1;
                    up[i][j] = (i > 0 ? up[i - 1][j] : 0) + 1;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int side = min(left[i][j], up[i][j]);

                while(side > ans) {

                    if(up[i][j - side + 1] >= side &&
                       left[i - side + 1][j] >= side) {
                        ans = side;
                    }
                    side--;
                }
            }
        }

        return ans * ans;
    }
};