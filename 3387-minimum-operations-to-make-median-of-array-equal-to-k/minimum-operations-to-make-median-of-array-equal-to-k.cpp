class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mid = n / 2;

        long long ans = 0;

        if (nums[mid] > k) {
            for (int i = mid; i >= 0; i--) {
                if (nums[i] <= k)
                    break;

                ans += nums[i] - k;
            }
        }
        else {
            for (int i = mid; i < n; i++) {
                if (nums[i] >= k)
                    break;

                ans += k - nums[i];
            }
        }
        return ans;
    }
};