class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        pq.push({0,{0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int ro = it.second.first;
            int col = it.second.second;
            
            if(ro == n-1 && col == m-1) return diff;

            for(int i = 0;i<4;i++){
                int nro = ro + dr[i];
                int ncol = col + dc[i];

                if(nro >= 0 && ncol >= 0 && nro < n && ncol < m){
                    
                    int neeffort = max(abs(heights[ro][col] - heights[nro][ncol]), diff);

                    if(neeffort < dist[nro][ncol]){
                        dist[nro][ncol] = neeffort;
                        pq.push({neeffort,{nro,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};