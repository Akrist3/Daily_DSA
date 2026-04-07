class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1)); 
        for(int j = 0; j < n; j++){
            dp[n-1][j] = a[n-1][j];
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                int d = a[i][j] + dp[i+1][j];
                int dg = a[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dg);
            }
        }
        
        return dp[0][0];
    }
};