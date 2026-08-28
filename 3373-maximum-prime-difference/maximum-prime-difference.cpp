class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int first = -1, last = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i])) {
                first = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (isPrime(nums[i])) {
                last = i;
                break;
            }
        }
        return last - first;
    }
};