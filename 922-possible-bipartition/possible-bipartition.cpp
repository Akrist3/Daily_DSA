class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);

        // Build graph
        for (auto &edge : dislikes) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // -1 = not colored
        //  0 = group 1
        //  1 = group 2
        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {

            // Start a new component
            if (color[i] != -1)
                continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {

                    // Same color -> impossible
                    if (color[v] == color[u]) {
                        return false;
                    }

                    // Color the unvisited node
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                }
            }
        }

        return true;
    }
};