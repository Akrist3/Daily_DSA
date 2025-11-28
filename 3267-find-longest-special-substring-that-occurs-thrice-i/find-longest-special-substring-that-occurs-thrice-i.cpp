#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int n = (int)s.size();

        // Collect consecutive runs for each character
        // Use 128 to be robust to any ASCII letters.
        array<vector<int>, 128> runsByChar;
        int maxRun = 0;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) ++j;
            int len = j - i;
            runsByChar[(unsigned char)s[i]].push_back(len);
            maxRun = max(maxRun, len);
            i = j;
        }

        if (maxRun == 0) return -1;

        auto can = [&](int L) -> bool {
            // For a fixed L, check if any single character
            // contributes at least 3 occurrences in total
            // (overlapping allowed) across its runs.
            for (int c = 0; c < 128; ++c) {
                long long cnt = 0;
                for (int len : runsByChar[c]) {
                    if (len >= L) {
                        cnt += (len - L + 1);
                        if (cnt >= 3) return true;
                    }
                }
            }
            return false;
        };

        int lo = 1, hi = maxRun, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};