class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Store (value, row, col)
        vector<tuple<int,int,int>> cells;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cells.push_back({grid[i][j], i, j});
            }
        }

        // Sort by height
        sort(cells.begin(), cells.end());

        DisjointSet ds(n * n);
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(auto &[time, r, c] : cells){
            vis[r][c] = true;

            int node = r * n + c;

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nc >= 0 && nr < n && nc < n && vis[nr][nc]){
                    int adjNode = nr * n + nc;
                    ds.unionBySize(node, adjNode);
                }
            }
            // Check if start and end are connected
            if(ds.findUpar(0) == ds.findUpar(n*n - 1)){
                return time;
            }
        }

        return -1; 
    }
};