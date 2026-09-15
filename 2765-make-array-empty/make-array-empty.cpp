#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        long long ans = n;
        int prevIndex = arr[0].second;
        for (int i = 1; i < n; i++) {
            int currIndex = arr[i].second;
            if (currIndex < prevIndex) {
                ans += n - i;
            }
            prevIndex = currIndex;
        }
        return ans;
    }
};