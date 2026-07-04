class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(string word : words){
            if(s.substr(0,word.size()) == word)cnt++;
        }
        return cnt;
    }
};