class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {

        // Sort robots and factories by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        // dp[i][j] = minimum distance for robots i...n
        // using factories j...m
        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(m + 1, -1)
        );

        function<long long(int, int)> solve = [&](int i, int j) -> long long {

            // All robots repaired
            if (i == n)
                return 0;

            // No factories left
            if (j == m)
                return 1e18;

            if (dp[i][j] != -1)
                return dp[i][j];

            // Option 1: Don't use this factory
            long long ans = solve(i, j + 1);

            // Option 2: Use this factory for k robots
            long long dist = 0;

            for (int k = 0; k < factory[j][1]; k++) {

                if (i + k >= n)
                    break;

                dist += abs(robot[i + k] - factory[j][0]);

                ans = min(
                    ans,
                    dist + solve(i + k + 1, j + 1)
                );
            }

            return dp[i][j] = ans;
        };

        return solve(0, 0);
    }
};