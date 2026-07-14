class Solution {
public:
    string intToRoman(int num) {
        // Create parallel arrays for values and corresponding symbols
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string roman;
        // Iterate through each value-symbol pair
        for (int i = 0; i < values.size() && num > 0; i++) {
            // Repeat while the current value can be subtracted from num
            while (num >= values[i]) {
                num -= values[i];
                roman += symbols[i];
            }
        }
        return roman;
    }
};