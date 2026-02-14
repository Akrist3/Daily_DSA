// this is a bfs Approach 
class Solution {
private:
    void bfs(int row,int col,vector<vector<int>> &vis ,vector<vector<int>> &grid){
        vis[row][col]= 1;
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;            
            int col = q.front().second; 
            q.pop();           
            for(int i = 0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow <n && ncol >= 0 && ncol <m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((i == 0|| i == n-1 || j == 0 ||j == m-1) && grid[i][j] == 1 && vis[i][j] == 0){
                    bfs(i,j,vis,grid);                    
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};