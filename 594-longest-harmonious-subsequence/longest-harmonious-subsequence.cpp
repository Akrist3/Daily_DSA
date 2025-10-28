class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int ,int>  freqn;
        for(int num : nums) freqn[num]++;
        int longest = 0;
        for(auto& [num,count]: freqn){
            if(freqn.count(num +1)){
                longest = max(longest,count + freqn[num +1]);
            }
        }
        return longest;
    }
};