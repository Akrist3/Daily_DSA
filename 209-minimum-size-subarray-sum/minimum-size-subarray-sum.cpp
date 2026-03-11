class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r= 0,sum = 0;
        int minlen = INT_MAX;
        for(r;r<n;r++){
            sum+= nums[r];
            while(sum >= target){
                minlen = min(minlen,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        if(minlen == INT_MAX) return 0;
        return minlen;
        
    }
};