class Solution {
    int rob1(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n < 1) return nums[0];
        int prev2= 0;
        int prev1 = nums[0];
        for(int i = 1;i<n;i++){
            int take = nums[i];
            if(i>1) take += prev2;
            int Nontake = 0 + prev1;
            int curi = max(take,Nontake);
            prev2 = prev1;
            prev1 = curi;
        }
        return prev1;
    };
public:
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0;i<n;i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
        
    }
};