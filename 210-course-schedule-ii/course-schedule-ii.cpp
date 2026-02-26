class Solution {
public:
    vector<int> findOrder(int numCou, vector<vector<int>>& prerequ) {
        vector<vector<int>> adj(numCou);
        vector<int> indegree(numCou, 0);

        for (auto &it : prerequ) {
            adj[it[1]].push_back(it[0]);   // edge
            indegree[it[0]]++;             // increase indegree
        }

        queue<int> q;
        for (int i = 0; i < numCou; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Kahn's Algorithm
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(topo.size() == numCou) return topo;
        return {};

    }
};