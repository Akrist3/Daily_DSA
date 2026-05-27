class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Apply operations
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Move non-zero elements to front
        vector<int> ans;

        for(int x : nums) {
            if(x != 0) ans.push_back(x);
        }

        // Fill remaining places with 0
        while(ans.size() < n) {
            ans.push_back(0);
        }

        return ans;
    }
};