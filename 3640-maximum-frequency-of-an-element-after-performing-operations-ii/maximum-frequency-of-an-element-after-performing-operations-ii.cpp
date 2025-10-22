class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<long long, long long> diff;   // difference map
        unordered_map<long long, long long> freq; // frequency map

        for (long long v : nums) {
            freq[v]++;
            diff[v - k] += 1;         // start of interval
            diff[v + k + 1] -= 1;     // end of interval (exclusive)
            diff[v] += 0;             // ensure v is a key so we evaluate target v
        }

        long long curr = 0, ans = 0;
        for (auto &p : diff) {
            long long x = p.first;
            long long d = p.second;
            curr += d;
            long long already = freq.count(x) ? freq[x] : 0;
            long long possible = min(curr, already + (long long)numOperations);
            ans = max(ans, possible);
        }
        return (int)ans;
    }
};