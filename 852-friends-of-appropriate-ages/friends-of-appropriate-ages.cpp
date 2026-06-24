class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121, 0);

        for (int age : ages)
            cnt[age]++;

        int ans = 0;

        for (int a = 1; a <= 120; a++) {
            for (int b = 1; b <= 120; b++) {

                if (b <= 0.5 * a + 7) continue;
                if (b > a) continue;
                if (b > 100 && a < 100) continue;

                ans += cnt[a] * cnt[b];

                if (a == b)
                    ans -= cnt[a];
            }
        }

        return ans;
    }
};