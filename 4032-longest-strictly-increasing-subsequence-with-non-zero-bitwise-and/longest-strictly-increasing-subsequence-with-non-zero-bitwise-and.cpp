class Solution {
public:
    int lis(vector<int>& arr) {
        vector<int> tail;

        for (int x : arr) {
            auto it = lower_bound(tail.begin(), tail.end(), x);

            if (it == tail.end())
                tail.push_back(x);
            else
                *it = x;
        }

        return tail.size();
    }

    int longestSubsequence(vector<int>& nums) {
        int ans = 0;

        for (int bit = 0; bit < 31; bit++) {
            vector<int> arr;

            for (int x : nums) {
                if ((x >> bit) & 1)
                    arr.push_back(x);
            }

            ans = max(ans, lis(arr));
        }

        return ans;
    }
};
