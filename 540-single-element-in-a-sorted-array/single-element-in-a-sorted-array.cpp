class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            // Make sure mid is even (because pairs start at even indices)
            if (mid % 2 == 1) mid--;

            // If the pair is valid, move right
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                r = mid;
            }
        }

        // l will stop at the single element
        return nums[l];
    }
};
