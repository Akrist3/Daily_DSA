class Solution {
public:
    int maxDistinct(string s) {
        bool seen[26] = {};
        int ans = 0;

        for (char c : s) {
            if (!seen[c - 'a']) {
                seen[c - 'a'] = true;
                ans++;
            }
        }

        return ans;
    }
};