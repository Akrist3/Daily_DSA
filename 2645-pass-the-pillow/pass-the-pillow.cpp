class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = n - 1; // time to go from 1 → n or n → 1
        int fullCycles = time / cycle; 
        int remainder = time % cycle;

        if (fullCycles % 2 == 0)
            return 1 + remainder; // moving forward
        else
            return n - remainder; // moving backward
    }
};
