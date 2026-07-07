class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        int ans = 0;

        // Check every pair (x, x + 1)
        for (auto &it : freq) {
            int num = it.first;
            if (freq.count(num + 1)) {
                ans = max(ans, freq[num] + freq[num + 1]);
            }
        }

        return ans;
    }
};