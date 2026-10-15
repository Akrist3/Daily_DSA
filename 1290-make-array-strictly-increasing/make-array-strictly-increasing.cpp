
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());

        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        const int INF = 1e9;

        // dp: last value -> minimum replacements
        map<int, int> dp;
        dp[-1] = 0;

        for (int x : arr1) {
            map<int, int> ndp;

            for (auto [last, ops] : dp) {
                // Option 1: Keep the current element
                if (x > last) {
                    auto it = ndp.find(x);
                    if (it == ndp.end() || it->second > ops) {
                        ndp[x] = ops;
                    }
                }

                // Option 2: Replace with the smallest
                // element in arr2 that is greater than last
                auto it = upper_bound(
                    arr2.begin(), arr2.end(), last
                );

                if (it != arr2.end()) {
                    int val = *it;
                    auto jt = ndp.find(val);

                    if (jt == ndp.end() || jt->second > ops + 1) {
                        ndp[val] = ops + 1;
                    }
                }
            }

            if (ndp.empty()) return -1;

            // Remove dominated states:
            // smaller last value with <= operations is better.
            dp.clear();
            int best = INF;

            for (auto [last, ops] : ndp) {
                if (ops < best) {
                    dp[last] = ops;
                    best = ops;
                }
            }
        }

        int ans = INF;
        for (auto [last, ops] : dp) {
            ans = min(ans, ops);
        }

        return ans == INF ? -1 : ans;
    }
};
