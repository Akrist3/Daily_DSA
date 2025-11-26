class Solution {
public:
int minimumMoves(vector<vector<int>>& grid) {
    int n = grid.size();
    // visited[r][c][dir] where dir: 0 = horizontal (cells (r,c),(r,c+1)), 1 = vertical (cells (r,c),(r+1,c))
    vector<vector<array<bool,2>>> visited(n, vector<array<bool,2>>(n, {false,false}));
    queue<tuple<int,int,int,int>> q; // r, c, dir, steps
    q.emplace(0, 0, 0, 0);
    visited[0][0][0] = true;

    int targetR = n - 1, targetC = n - 2; // desired top-left for horizontal at bottom-right
    while (!q.empty()) {
        auto [r, c, dir, steps] = q.front(); q.pop();
        // check target
        if (r == targetR && c == targetC && dir == 0) return steps;

        // 1) Move Right
        if (dir == 0) { // horizontal: occupies (r,c) and (r,c+1) -> need (r,c+2) free
            if (c + 2 < n && grid[r][c+2] == 0 && !visited[r][c+1][0]) {
                visited[r][c+1][0] = true;
                q.emplace(r, c+1, 0, steps+1);
            }
        } else { // vertical: occupies (r,c) and (r+1,c) -> need (r,c+1) and (r+1,c+1) free
            if (c + 1 < n && grid[r][c+1] == 0 && grid[r+1][c+1] == 0 && !visited[r][c+1][1]) {
                visited[r][c+1][1] = true;
                q.emplace(r, c+1, 1, steps+1);
            }
        }

        // 2) Move Down
        if (dir == 0) { // horizontal: need (r+1,c) and (r+1,c+1) free
            if (r + 1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0 && !visited[r+1][c][0]) {
                visited[r+1][c][0] = true;
                q.emplace(r+1, c, 0, steps+1);
            }
        } else { // vertical: need (r+2,c) free
            if (r + 2 < n && grid[r+2][c] == 0 && !visited[r+1][c][1]) {
                visited[r+1][c][1] = true;
                q.emplace(r+1, c, 1, steps+1);
            }
        }

        // 3) Rotate (toggle orientation) — both rotations require 2x2 block free
        if (dir == 0) { // horizontal -> vertical pivot at (r,c)
            if (r + 1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0 && !visited[r][c][1]) {
                visited[r][c][1] = true;
                q.emplace(r, c, 1, steps+1);
            }
        } else { // vertical -> horizontal pivot at (r,c)
            if (c + 1 < n && grid[r][c+1] == 0 && grid[r+1][c+1] == 0 && !visited[r][c][0]) {
                visited[r][c][0] = true;
                q.emplace(r, c, 0, steps+1);
            }
        }
    }

    return -1;
}
};