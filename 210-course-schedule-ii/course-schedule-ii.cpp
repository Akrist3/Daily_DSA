class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);  // edge: prereq -> course
        }

        vector<int> state(numCourses, 0); // 0=unvisited,1=visiting,2=visited
        vector<int> order;
        bool hasCycle = false;

        function<void(int)> dfs = [&](int node) {
            if (state[node] == 1) {        // found a back edge -> cycle
                hasCycle = true;
                return;
            }
            if (state[node] == 2) return;  // already done

            state[node] = 1;               // mark as visiting
            for (int nxt : graph[node]) {
                if (hasCycle) return;
                dfs(nxt);
            }
            state[node] = 2;               // mark as visited
            order.push_back(node);         // add after all neighbors
        };

        for (int i = 0; i < numCourses && !hasCycle; ++i) {
            if (state[i] == 0)
                dfs(i);
        }

        if (hasCycle) 
            return {};

        reverse(order.begin(), order.end()); // reverse for topo order
        return order;
    }
};
