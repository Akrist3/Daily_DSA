class Solution {
public:
    vector<int> parent, rankv;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return;

        if(rankv[pa] < rankv[pb]) parent[pa] = pb;
        else if(rankv[pb] < rankv[pa]) parent[pb] = pa;
        else{
            parent[pb] = pa;
            rankv[pa]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1) return -1;

        parent.resize(n);
        rankv.resize(n,0);

        for(int i=0;i<n;i++) parent[i] = i;

        for(auto &it : connections){
            unite(it[0], it[1]);
        }

        int components = 0;

        for(int i=0;i<n;i++){
            if(find(i) == i) components++;
        }

        return components - 1;
    }
};