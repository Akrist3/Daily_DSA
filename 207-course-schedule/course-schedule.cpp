#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCou, vector<vector<int>>& prerequ) {

        // Step 1: Create adjacency list
        vector<vector<int>> adj(numCou);
        vector<int> indegree(numCou, 0);

        for (auto &it : prerequ) {
            adj[it[1]].push_back(it[0]);   // edge
            indegree[it[0]]++;             // increase indegree
        }

        // Step 2: Push nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < numCou; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Kahn's Algorithm
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Step 4: Check cycle
        return cnt == numCou;
    }
};