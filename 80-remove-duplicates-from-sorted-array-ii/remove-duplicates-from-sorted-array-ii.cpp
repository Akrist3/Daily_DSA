class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        int fir = 2;

        for(int move = 2; move < n; move++){
            if(nums[move] != nums[fir - 2]){
                nums[fir] = nums[move];
                fir++;
            }
        }
        return fir;
    }
};