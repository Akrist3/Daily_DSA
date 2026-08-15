class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);

        for (char c : s){
            freq[c-'a']++;
        }
        unordered_set<int> used;
        int cnt = 0;
        for(int f: freq){
            while(f > 0 && used.count(f)){
                f--;
                cnt++;
            }
            if(f > 0){
                used.insert(f);
            }
        }
        return cnt;        
    }
};