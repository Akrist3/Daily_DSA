class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;

        for (int x : arr1) {
            // Find first element >= x
            auto it = lower_bound(arr2.begin(), arr2.end(), x);

            bool valid = true;

            // Check right neighbor
            if (it != arr2.end() && abs(*it - x) <= d) {
                valid = false;
            }

            // Check left neighbor
            if (it != arr2.begin()) {
                it--;
                if (abs(*it - x) <= d) {
                    valid = false;
                }
            }

            if (valid) count++;
        }

        return count;
    }
};