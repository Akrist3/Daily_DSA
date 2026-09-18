class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> mismatch;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                mismatch.push_back(i);
            }
        }
        if (mismatch.size() == 0)
            return true;

        if (mismatch.size() != 2)
            return false;

        int i = mismatch[0];
        int j = mismatch[1];
        return s1[i] == s2[j] && s1[j] == s2[i];
    }
};