class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int k = s.size();
        int d = digits.size();

        int total = 0;

        // 1. Numbers with length < k
        for (int len = 1; len < k; len++) {
            total += pow(d, len);
        }

        // 2. Numbers with same length
        for (int i = 0; i < k; i++) {
            bool hasSame = false;

            for (string digit : digits) {
                if (digit[0] < s[i]) {
                    total += pow(d, k - i - 1);
                }
                else if (digit[0] == s[i]) {
                    hasSame = true;
                }
            }
            if (!hasSame) return total;
        }
        // Include n itself
        return total + 1;
    }
};