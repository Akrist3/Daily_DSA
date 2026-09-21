class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sr = 0, sc = 0;
        int totalKeys = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    sr = i;
                    sc = j;
                }

                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    totalKeys++;
                }
            }
        }

        int allKeys = (1 << totalKeys) - 1;
        vector<vector<vector<bool>>> visited(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(1 << totalKeys, false)
            )
        );
        queue<tuple<int, int, int>> q;

        q.push({sr, sc, 0});
        visited[sr][sc][0] = true;
        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c, mask] = q.front();
                q.pop();

                // Collected all keys
                if (mask == allKeys) {
                    return steps;
                }

                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    char cell = grid[nr][nc];

                    // Wall
                    if (cell == '#')
                        continue;

                    int newMask = mask;
                    // Lock
                    if (cell >= 'A' && cell <= 'F') {
                        int key = cell - 'A';
                        if (!(mask & (1 << key)))
                            continue;
                    }
                    // Key
                    if (cell >= 'a' && cell <= 'f') {
                        newMask |= (1 << (cell - 'a'));
                    }
                    if (visited[nr][nc][newMask])
                        continue;

                    visited[nr][nc][newMask] = true;

                    q.push({nr, nc, newMask});
                }
            }
            steps++;
        }
        return -1;
    }
};