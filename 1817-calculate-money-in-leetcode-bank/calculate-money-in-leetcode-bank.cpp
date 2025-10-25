class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int start = 1; // money deposited on first Monday
        
        while (n > 0) {
            for (int i = 0; i < 7 && n > 0; i++) {
                total += start + i;
                n--;
            }
            start++; // next week starts with +1
        }
        return total;
    }
};
