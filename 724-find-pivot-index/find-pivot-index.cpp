class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int lsum = 0;
        for(int it : nums){
            total+=it;
        }
        for(int i = 0;i<n;i++){
            if(lsum == total - lsum - nums[i]){
                return i;
            }
            lsum += nums[i];
        }
        return -1;        
    }
};