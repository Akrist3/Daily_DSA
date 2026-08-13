class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        int totalOnes = count(s.begin(), s.end(), '1');
        vector<bool> ans;
        for (string &t : strs) {
            int fixedOnes = 0;
            int question = 0;
            for (char c : t) {
                if (c == '1')
                    fixedOnes++;
                else if (c == '?')
                    question++;
            }
            int need = totalOnes - fixedOnes;
            if (need < 0 || need > question) {
                ans.push_back(false);
                continue;
            }
            vector<int> take(n, 0);

            for (int i = n - 1; i >= 0 && need > 0; i--) {
                if (t[i] == '?') {
                    take[i] = 1;
                    need--;
                }
            }
            int sourceOnes = 0;
            int targetOnes = 0;
            bool possible = true;

            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                    sourceOnes++;

                if (t[i] == '1' || take[i])
                    targetOnes++;
                if (targetOnes > sourceOnes) {
                    possible = false;
                    break;
                }
            }
            ans.push_back(possible);
        }
        return ans;
    }
};