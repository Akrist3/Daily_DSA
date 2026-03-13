class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<string> valid = {"1","2","145","40585"};
        string s =to_string(n);
        sort(s.begin(),s.end());
        for(string t : valid){
            
            sort(t.begin(),t.end());
            if((s == t)){
                return true;
            }
        }
            return false;
    }
};