class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>mat(n,vector<int>(n));
        int top = 0, bottom = n-1;
        int left = 0, right = n-1;
        int cnt = 1;
        while (top <= bottom && left <= right){
            // left ->right
            for(int i = left;i<= right;i++)
                mat[top][i]= cnt++;
            top++;  
            // top ->bottom
            for(int i = top;i<= bottom;i++)
                mat[i][right]= cnt++;
            right--;
            // right->left
            for(int i =right;i >= left;i--)
                mat[bottom][i]=  cnt++;
            bottom--;
            // bootom -> top
            for(int i = bottom;i >= top;i--)
                mat[i][left] = cnt++;
            left++;
            
        }
        return mat;
        
    }
};