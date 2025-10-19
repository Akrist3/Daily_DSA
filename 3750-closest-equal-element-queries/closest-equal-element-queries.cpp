class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> dist(n, n); 
        unordered_map<int, int> lastSeen; 
        // Traverse twice to handle circular nature
        for (int i = 0; i < 2 * n; ++i) {
            int idx = i % n;
            int val = nums[idx];

            if (lastSeen.count(val)) {
                int prev = lastSeen[val];
                int d = i - prev;
                int prevIdx = prev % n;

                dist[idx] = min(dist[idx], d);
                dist[prevIdx] = min(dist[prevIdx], d);
            }

            lastSeen[val] = i;
        }
        // Build result for each query
        vector<int> ans;
        ans.reserve(queries.size());
        for (int q : queries) {
            ans.push_back(dist[q] < n ? dist[q] : -1);
        }
        return ans;
    }
};
