class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int index = -1;
        
        for (int i = 0; i < n; i++) {
            if (number[i] == digit) {
                index = i;
                if (i + 1 < n && number[i + 1] > number[i]) {
                    index = i;
                    break;
                }
            }
        }
        
        return number.substr(0, index) + number.substr(index + 1);
    }
};
