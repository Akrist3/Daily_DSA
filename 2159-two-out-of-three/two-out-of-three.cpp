class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        set<int> s3(nums3.begin(), nums3.end());

        map<int, int> count;

        for (int x : s1) count[x]++;
        for (int x : s2) count[x]++;
        for (int x : s3) count[x]++;

        vector<int> result;
        for (auto [num, c] : count) {
            if (c >= 2) result.push_back(num);
        }
        return result;
    }
};