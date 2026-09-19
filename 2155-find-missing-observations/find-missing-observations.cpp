class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int total = mean * (m + n);
        int missingSum = total - sum;
        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = 1;
        }
        int extra = missingSum - n;
        for (int i = 0; i < n && extra > 0; i++) {
            int add = min(5, extra);

            ans[i] += add;
            extra -= add;
        }
        return ans;
    }
};