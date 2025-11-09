class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        for (int x : nums) totalSum += x;

        long long leftSum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long rightSum = totalSum - leftSum - nums[i];
            if (nums[i] == 0) {
                if (leftSum == rightSum) ans += 2;
                else if (abs(leftSum - rightSum) == 1) ans += 1;
            }
            leftSum += nums[i];
        }
        return ans;
    }
};
