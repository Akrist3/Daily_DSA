class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> needed(n);

        for (int i = 0; i < n; i++) {
            needed[i] = capacity[i] - rocks[i];
        }

        sort(needed.begin(), needed.end());

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (additionalRocks >= needed[i]) {
                additionalRocks -= needed[i];
                ans++;
            } else {
                break;
            }
        }

        return ans;
    }
};