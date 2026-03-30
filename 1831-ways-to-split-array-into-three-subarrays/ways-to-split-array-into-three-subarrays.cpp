class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        vector<long long> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i-1] + nums[i];
        long long ans = 0;
        for(int i = 0; i < n-2; i++) {
            // left sum
            long long left = pre[i];
            // binary search for j1
            int l = i+1, r = n-2, j1 = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(pre[mid] - pre[i] >= left) {
                    j1 = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            // binary search for j2
            l = i+1, r = n-2;
            int j2 = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(pre[mid] - pre[i] <= pre[n-1] - pre[mid]) {
                    j2 = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if(j1 != -1 && j2 != -1 && j1 <= j2) {
                ans = (ans + (j2 - j1 + 1)) % mod;
            }
        }
        return ans;
    }
};