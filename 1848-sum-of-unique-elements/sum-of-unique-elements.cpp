class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }
        int sum = 0;
        for(auto it : mp){
            int nu = it.first;
            int cnt = it.second;
            if(cnt == 1)sum+=nu;
        }
        
        return sum;
    }
};