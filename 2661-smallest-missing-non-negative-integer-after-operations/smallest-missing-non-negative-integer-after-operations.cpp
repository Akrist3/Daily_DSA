class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            int mod = ((n % value) + value) % value; // normalize negative mods
            freq[mod]++;
        }

        for (int x = 0;; x++) {
            int mod = x % value;
            if (freq[mod] == 0) return x;
            freq[mod]--;
        }
        return -1; // never reached
    }
};