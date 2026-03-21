class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }

    int count(vector<int>& nums, int bound) {
        int ans = 0, curr = 0;

        for(int x : nums) {
            if(x <= bound) {
                curr++;        // extend valid subarray
            } else {
                curr = 0;      // reset
            }
            ans += curr;
        }

        return ans;
    }
};