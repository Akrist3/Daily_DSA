class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        // Step 1: first & last occurrence
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        vector<pair<int,int>> intervals;
        // Step 2: create valid intervals
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) continue;
            int l = first[i], r = last[i];
            bool valid = true;
            for (int j = l; j <= r; j++) {
                int c = s[j] - 'a';
                if (first[c] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[c]);
            }
            if (valid) intervals.push_back({l, r});
        }

        // Step 3: sort by end
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });

        // Step 4: greedy pick
        vector<string> result;
        int prevEnd = -1;

        for (auto &it : intervals) {
            if (it.first > prevEnd) {
                result.push_back(s.substr(it.first, it.second - it.first + 1));
                prevEnd = it.second;
            }
        }
        return result;
    }
};