class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> preMax(n), sufMin(n);

        preMax[0] = nums[0];
        for (int i = 1; i < n; i++)
            preMax[i] = max(preMax[i - 1], nums[i]);

        sufMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            sufMin[i] = min(sufMin[i + 1], nums[i]);

        vector<int> ans(n);

        int start = 0;
        int mx = nums[0];

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);

            if (i == n - 1 || preMax[i] <= sufMin[i + 1]) {
                for (int j = start; j <= i; j++)
                    ans[j] = mx;

                start = i + 1;
                if (start < n)
                    mx = nums[start];
            }
        }

        return ans;
    }
};