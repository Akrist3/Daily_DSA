class Solution {
    bool f(int n, int sum, vector<int> &arr){
        vector<bool> prev(sum+1, false), cur(sum+1, false);

        prev[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;

        for(int ind = 1; ind < n; ind++){
            cur[0] = true;

            for(int target = 1; target <= sum; target++){
                bool notTake = prev[target];
                bool take = false;

                if(arr[ind] <= target)
                    take = prev[target - arr[ind]];

                cur[target] = take || notTake;
            }
            prev = cur;
        }
        return prev[sum];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int totalSum = 0;
        for(auto it : nums) totalSum += it;

        if(totalSum % 2) return false;

        return f(n, totalSum/2, nums);
    }
};