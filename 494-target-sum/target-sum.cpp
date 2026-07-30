class Solution {
public:
    int findways(vector<int> & num,int tar){
        int n = num.size();
        vector<int> prev(tar + 1,0),cur(tar +1,0);
        if(num[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(num[0] != 0 && num[0] <= tar) prev[num[0]] = 1;
        for(int ind = 1;ind<n;ind++){
            for(int sum = 0;sum <= tar;sum++){
                int nottake = prev[sum];
                int take = 0;
                if(num[ind]<=sum) take = prev[sum - num[ind]];
                cur[sum] = (nottake + take);
            }
            prev = cur;
        }
        return prev[tar];
    }
    int countpartition(int n,int d,vector<int> & arr){
        int tosum = 0;
        for(auto it : arr)tosum += it;
        if(tosum -d < 0 || (tosum - d) % 2) return false;
        return findways(arr,(tosum -d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countpartition(n,target,nums);
    }
};