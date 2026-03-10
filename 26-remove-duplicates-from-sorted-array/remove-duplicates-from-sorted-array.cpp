class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(),nums.end());
        nums.clear();
        for(auto it : st){
            nums.push_back(it);
        }
        return nums.size();
    }
};