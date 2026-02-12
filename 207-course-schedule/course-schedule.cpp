class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        
        vis[node] = 1;   // visiting
        
        for(auto adjacentNode : adj[node]){
            if(vis[adjacentNode] == 0){
                if(dfs(adjacentNode, vis, adj) == true)
                    return true;
            }
            else if(vis[adjacentNode] == 1){
                return true;   // cycle found
            }
        }
        
        vis[node] = 2;   // visited completely
        return false;
    }

public:
    bool canFinish(int v, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(v);
        
        // build graph
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(v, 0);
        for(int i = 0; i < v; i++){
            if(vis[i] == 0){
                if(dfs(i, vis, adj) == true)
                    return false;   // cycle exists
            }
        }
        return true;   // no cycle
    }
};
