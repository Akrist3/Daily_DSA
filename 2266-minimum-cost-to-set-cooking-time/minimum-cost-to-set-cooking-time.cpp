class Solution {
public:
    int cost(string s, int startAt, int moveCost, int pushCost) {
        int ans = 0;
        int cur = startAt;

        for (char c : s) {
            int d = c - '0';
            if (cur != d) ans += moveCost;
            ans += pushCost;
            cur = d;
        }

        return ans;
    }

    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int ans = INT_MAX;

        int m = targetSeconds / 60;
        int s = targetSeconds % 60;

        auto check = [&](int mm, int ss) {
            if (mm < 0 || mm > 99 || ss < 0 || ss > 99)
                return;

            string str;

            if (mm > 0)
                str += to_string(mm);

            if (mm > 0) {
                if (ss < 10)
                    str += "0";
                str += to_string(ss);
            } else {
                str += to_string(ss);
            }

            ans = min(ans, cost(str, startAt, moveCost, pushCost));
        };

        check(m, s);

        if (m > 0 && s + 60 <= 99)
            check(m - 1, s + 60);

        return ans;
    }
};