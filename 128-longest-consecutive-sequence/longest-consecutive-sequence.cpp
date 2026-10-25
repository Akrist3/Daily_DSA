class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int cnt = 1;
        int longest = 1;
        sort(nums.begin(),nums.end());
        for(int i = 1; i<n;i++){
            if(nums[i] == nums[i-1]){
                continue;
            }else if(nums[i] == nums[i-1]+1) cnt++;
            else cnt = 1;
            longest = max(longest,cnt);
        }
        return longest;
    }
};
