class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        int left = 0;
        int ans = 0;
        int n = nums.size();

        for (auto& [value, freq] : mp) {
            int right = n - left - freq;

            ans += left * freq * right;

            left += freq;
        }

        return ans;
    }
};