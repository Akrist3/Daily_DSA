class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<bool> sorted(n - 1, false);
        int res = 0;

        for (int col = 0; col < m; ++col) {
            bool needDelete = false;

            // Check if keeping this column breaks the order
            for (int i = 0; i < n - 1; ++i) {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    needDelete = true;
                    break;
                }
            }

            // If deletion needed, increment result
            if (needDelete) {
                res++;
                continue;
            }

            // Otherwise, update sorted pairs
            for (int i = 0; i < n - 1; ++i) {
                if (!sorted[i] && strs[i][col] < strs[i + 1][col])
                    sorted[i] = true;
            }
        }

        return res;
    }
};